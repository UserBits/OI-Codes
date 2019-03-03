#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long a[105],num,i=0;
    scanf("%lld",&num);
    while(num!=0)
    {
        a[i++]=num;
        scanf("%lld",&num);
    }
    while(i--)
        printf("%lld ",a[i]);
    return 0;
}
