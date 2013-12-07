#include <iostream>
#include <time.h>
using namespace std;
typedef struct RSA_PARAM_Tag
{
	unsigned _int64 p, q;
	unsigned _int64 f;
	unsigned _int64 n,e;
	unsigned _int64 d;
}
RSA_PARAM;
const static long g_PrimeTable[]= {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
const static long g_PrimeCount = sizeof(long); 
const unsigned _int64 multiplier = 12747293821;
const unsigned _int64 adder = 1343545677842234541;

class	RandNumber
{
private:
	unsigned _int64 randSeed;
public:
	RandNumber(unsigned _int64 s=0);
	unsigned _int64 Random(unsigned _int64 n);
};

RandNumber::RandNumber(unsigned _int64 s)
{
	if (!s)
	{
		randSeed = (unsigned _int64)time(NULL);
	}
	else
	{
		randSeed =s;
	}
}
unsigned _int64 RandNumber::Random(unsigned _int64 n)
{
	randSeed = multiplier * randSeed + adder;
	return randSeed % n;
}

static RandNumber g_Rnd;
inline unsigned _int64 MulMod(unsigned _int64  a, unsigned _int64 b, unsigned _int64 n)
{
	return a*b % n;
}
unsigned _int64 PowMod(unsigned _int64 base, unsigned _int64 pow, unsigned _int64 &n)
{
	unsigned _int64 a=base, b=pow, c=1;
	while(b)
	{
		while(!(b&1))
		{
			b>>=1;
			a = MulMod(a, a, n);
		}
		b--;
		c=MulMod(a, c, n);
	}
	return c;
}

long RabinMillerKnl(unsigned _int64 &n)
{
	unsigned _int64 b, m, j, v, i;
	m= n-1;
	j=0;
	while(!(m&1))
	{
		++j;
		m>>=1;
	}
	b= 2+g_Rnd.Random(n-3);
	v=PowMod(b, m, n);
	if (v== 1)
	{
		return 1;
	}
	i=1;
	while(v != n-1)
	{
		if (i == j)
		{
			return 0;
		}
		v = PowMod(v, 2, n);
		++i;
	}
	return 1;
}

long RabinMiller(unsigned _int64 &n, long loop)
{
	for (long i=0; i<g_PrimeCount; i++)
	{
		if (n % g_PrimeTable[i] == 0)
		{
			return 0;
		}
	}
	for (long i=0; i<loop; i++)
	{
		if (!RabinMillerKnl(n))
		{
			return 0;
		}
	}
	return 1;
}

unsigned _int64 RandomPrime(char bits)
{
	unsigned _int64 base;
	do
	{
		base=(unsigned long)1<<(bits -1);
		base+=g_Rnd.Random(base);
		base|=1;
	}
	while (!RabinMiller(base, 30));
	return base;
}

unsigned _int64 EuclidGcd(unsigned _int64 &p, unsigned _int64 &q)
{
	unsigned _int64 a=p>q?p:q;
	unsigned _int64 b=p<1?p:q;
	unsigned _int64 t;
	if (p==q)
	{
		return p;
	}
	else
	{
		while(b)
		{
			a=a%b;
			t=a;
			a=b;
			b=t;
		}
		return a;
	}
}

unsigned _int64 SteinGcd(unsigned _int64 &p, unsigned _int64 &q)
{
	unsigned _int64 a=p>q?p:q;
	unsigned _int64 b=p<1?p:q;
	unsigned _int64 t, r=1;
	if (p==q)
	{
		return p;
	}
	else
	{
		while((!(a&1)) && (!(b&1)))
		{
			r<<=1;
			a>>=1;
			b>>=1;
		}
		if (!(a&1))
		{
			t=a;
			a=b;
			b=t;
		}
		do
		{
			while (!(b&1))
			{
				b>>=1;
			}
			if (b<a)
			{
				t=a;
				a=b;
				b=t;
			}
			b=(b-a)>>1;
		}
		while (b);
		return r*a;
	}
}

unsigned _int64 Euclid(unsigned _int64 &a, unsigned _int64 &b)
{
	unsigned _int64 m, e, i, j, x, y;
	long xx, yy;
	m=b;
	e=a;
	x=0;
	y=1;
	xx=1;
	yy=1;
	while (e)
	{
		i=m/e;
		j=m%e;
		m=e;
		e=j;
		j=y;
		y*=i;
		if (xx==yy)
		{
			if (x>y)
			{
				y=x-y;
			}
			else
			{
				y-=x;
				yy=0;
			}
		}
		else
		{
			y+=x;
			xx=1-xx;
			yy=1-yy;
		}
		x=j;
	}
	if (xx==0)
	{
		x=b-x;
	}
	return x;
}

RSA_PARAM RsaGetParam(void)
{
	RSA_PARAM Rsa={0};
	unsigned _int64 t;
	Rsa.p=RandomPrime(16);
	Rsa.q=RandomPrime(16);
	Rsa.n=Rsa.p * Rsa.q;
	Rsa.f=(Rsa.p -1)*(Rsa.q-1);
	do
	{
		Rsa.e=g_Rnd.Random(65536);
		Rsa.e|=1;
	}
	while (SteinGcd(Rsa.e, Rsa.f) !=1);
	return Rsa;
}

int main(void)
{
	RSA_PARAM r;
	char pSrc[5];
	const unsigned long n=sizeof(pSrc);
	unsigned char *q, pDec[n];
	unsigned _int64 pEnc[n];
	r=RsaGetParam();
	cout<<"p="<<r.p << endl;
	cout<<"q="<<r.q << endl;
	cout<<"f=(p-1)*(q-1)="<<r.f << endl;
	cout<<"n=p*q="<<r.n << endl;
	cout<<"e="<<r.e << endl;
	cout<<"d="<<r.d << endl;

	cout<<endl<<" Chiness word1:";
	cin>>pSrc;
	q=(unsigned char *)pSrc;
	cout<<endl<<" Chiness word2:";
	for (unsigned long i=0; i<n; i++)
	{
		pEnc[i]=PowMod(q[i], r.e, r.n);
		cout<<hex<<pEnc[i]<<"";
	}
	cout<<endl<<endl;
	for (unsigned long i=0; i<n; i++)
	{
		pDec[i]=PowMod(pEnc[i], r.d, r.n);
	}
	cout<<"chiness word3:"<<(char *)pDec<<endl<<endl;
	return 0;
}

















