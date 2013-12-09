#include <iostream>
#include <string>
#include <time.h>

#ifndef __int64
#define __int64 long long
#endif

using namespace std;
typedef struct RSA_PARAM_Tag
{
	unsigned __int64 p, q;  // p and q are two primes
	unsigned __int64 f;	// f=(p-1)*(q-1)
	unsigned __int64 n, e;	// n=pq; gcd(e,f)=1 public keys
	unsigned __int64 d;	// private key, ed=1(mod f), gcd(n,d)=1
}RSA_PARAM;


const static long g_PrimeTable[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 }; 
const static long g_PrimeCount = sizeof(long);
const unsigned __int64 multiplier = 12747293821;
const unsigned __int64 adder = 1343545677842234541;

// Random number
class RandNumber
{
private:
	unsigned __int64 randSeed;
public:
	RandNumber(unsigned __int64 s = 0);
	unsigned __int64 Random(unsigned __int64 n);
};

RandNumber::RandNumber(unsigned __int64 s)
{// Initialize seed using system time, if there is no initialized seed.
	if (!s)
	{
		randSeed = (unsigned __int64)time(NULL);
	}
	else
	{
		randSeed = s;
	}
}
unsigned __int64 RandNumber::Random(unsigned __int64 n)
{
	randSeed = multiplier * randSeed + adder;
	return randSeed % n;
}static RandNumber g_Rnd;	

inline unsigned __int64 MulMod(unsigned __int64  a, unsigned __int64 b, unsigned __int64 n)
{
	return a*b % n;  // x=ab(mod n)
}	// use inline to speed up.


unsigned __int64 PowMod(unsigned __int64 base, unsigned __int64 pow, unsigned __int64 &n)
{
	unsigned __int64 a = base, b = pow, c = 1;
	while (b)
	{
		while (!(b & 1))
		{
			b >>= 1;
			a = MulMod(a, a, n);  // a=a*a % n
		}	// actually, there is a overflow risk
		b--;
		c = MulMod(a, c, n);
	}
	return c;
}

long RabinMillerKnl(unsigned __int64 &n)
{
	unsigned __int64 b, m, j, v, i;
	m = n - 1;
	j = 0;
	while (!(m & 1))
	{
		++j;
		m >>= 1;
	}
	b = 2 + g_Rnd.Random(n - 3);  // randomly select a b
	v = PowMod(b, m, n);  // v=(b^m) mod n
	if (v == 1)
	{
		return 1;
	}  // it is a prime!
	i = 1;
	while (v != n - 1)
	{
		if (i == j)
		{
			return 0;
		}  // it is not a prime!
		v = PowMod(v, 2, n);
		++i;
	}
	return 1;
}

long RabinMiller(unsigned __int64 &n, long loop)
{
	for (long i = 0; i<g_PrimeCount; i++)
	{
		if (n % g_PrimeTable[i] == 0)
		{
			return 0;
		}  // test if it is a prime with some small prime numbers.
	}
	for (long i = 0; i<loop; i++)
	{
		if (!RabinMillerKnl(n))
		{
			return 0;  // Again, we use Rabin-Miller test for the efficiency
		}
	}
	return 1;
}

unsigned __int64 RandomPrime(char bits)
{// randomly generate a prime number, at most 32 bits
	unsigned __int64 base;
	do
	{
		base = (unsigned long)1 << (bits - 1);  // big endian must be 1
		base += g_Rnd.Random(base);
		base |= 1;  // small endian must be 1
	} while (!RabinMiller(base, 30));
	return base;  // if pass 30 times of RM test, then it "should" be a prime number
}

unsigned __int64 EuclidGcd(unsigned __int64 &p, unsigned __int64 &q)
{// In Euclidian method we trust.
	unsigned __int64 a = p>q ? p : q;
	unsigned __int64 b = p<q ? p : q;
	unsigned __int64 t;
	if (p == q)
	{
		return p;  // equal, then the gcd() is itself.
	}
	else
	{
		while (b)  // gcd(a,b)=gcd(b,a-qb)
		{
			a = a%b;
			t = a;
			a = b;
			b = t;
		}
		return a;
	}
}

unsigned __int64 SteinGcd(unsigned __int64 &p, unsigned __int64 &q)
{// Yet another workaround to obtain gcd()
	unsigned __int64 a = p>q ? p : q;
	unsigned __int64 b = p<q ? p : q;
	unsigned __int64 t, r = 1;
	if (p == q)
	{
		return p;
	}
	else
	{
		while ((!(a & 1)) && (!(b & 1)))  // both a and b are even numbers!
		{
			r <<= 1;
			a >>= 1;
			b >>= 1;
		}
		if (!(a & 1))  // a is even, swap a and b
		{
			t = a;
			a = b;
			b = t;
		}
		do
		{
			while (!(b & 1))  // b is even, a is odd. then...
			{
				b >>= 1;
			}
			if (b<a)
			{
				t = a;
				a = b;
				b = t;
			}
			b = (b - a) >> 1;
		} while (b);
		return r*a;
	}
}

unsigned __int64 Euclid(unsigned __int64 &a, unsigned __int64 &b)
{// transform the congruence to......ax-by=1, find out the least possible x
	unsigned __int64 m, e, i, j, x, y;
	long xx, yy;
	m = b;
	e = a;
	x = 0;
	y = 1;
	xx = 1;
	yy = 1;
	while (e)
	{
		i = m / e;
		j = m%e;
		m = e;
		e = j;
		j = y;
		y *= i;
		if (xx == yy)
		{
			if (x>y)
			{
				y = x - y;
			}
			else
			{
				y -= x;
				yy = 0;
			}
		}
		else
		{
			y += x;
			xx = 1 - xx;
			yy = 1 - yy;
		}
		x = j;
	}
	if (xx == 0)
	{
		x = b - x;
	}
	return x;
}

RSA_PARAM RsaGetParam(void)
{
	RSA_PARAM Rsa = { 0 };
	unsigned __int64 t;
	Rsa.p = RandomPrime(16);  // generate two primes
	Rsa.q = RandomPrime(16);
	Rsa.n = Rsa.p * Rsa.q;
	Rsa.f = (Rsa.p - 1)*(Rsa.q - 1);
	do
	{
		Rsa.e = g_Rnd.Random(65536);  // less than 65536(2^16)
		Rsa.e |= 1;  // must be odd since f=(p-1)(q-1) must be an even number!
	} while (SteinGcd(Rsa.e, Rsa.f) != 1);
	Rsa.d = Euclid(Rsa.e, Rsa.f);
	return Rsa;
}

int main(void)
{
	RSA_PARAM r;
	r = RsaGetParam();
	cout << "p=" << r.p << endl;
	cout << "q=" << r.q << endl;
	cout << "f=(p-1)*(q-1)=" << r.f << endl;
	cout << "n=p*q=" << r.n << endl;
	cout << "e=" << r.e << endl;
	cout << "d=" << r.d << endl;

	string str;
	cout << endl << " Please enter your plaintext: ";
	// cin >> str;
        getline(cin, str);
	const char * pSrc = str.c_str();
	const unsigned long n = str.length() + 1;
	unsigned char* q = (unsigned char *)pSrc;
	unsigned char pDec[n];
	unsigned __int64 pEnc[n];

	cout << endl << " Ciphertext is: ";
	for (unsigned long i = 0; i<n; i++)
	{
		pEnc[i] = PowMod(q[i], r.e, r.n);
		cout << hex << pEnc[i] << " ";
	}
	cout << endl << endl;

	cout << "Decipher: ";
	for (unsigned long i = 0; i<n; i++)
	{
		pDec[i] = PowMod(pEnc[i], r.d, r.n);
	}
	cout << " You plaintext should be: " << (char *)pDec << endl << endl;
	
	return 0;
}
