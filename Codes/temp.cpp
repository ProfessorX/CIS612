__int64 HiGcd(__int64 i, __int64 j)
{
    __int64 temp;
    do
    {
        temp=i%j;
        if(temp!=0)
        {
            i=j;
            j=temp;
        }
    }while(temp!=0);
    return j;
}
