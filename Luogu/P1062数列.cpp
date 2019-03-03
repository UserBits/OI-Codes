#include<iostream>
#include<cstdio>
using namespace std;
typedef long long lng;
int a[1005];
lng pow(lng a,lng p)
{
	long long result=1;
	while(p>0)
	{
		if(p%2==1)
			result=result*a;
		p/=2;
		a=a*a;
	}
	return result;
}
int main()
{
    lng ans=0;
	int n,k,len=0;
    scanf("%d%d",&n,&k);
    while(k)
	{
		a[++len]=k%2;
		k/=2;
	}
    for(int i=len;i>0;i--)
        ans+=pow(n,i-1)*a[i];
    printf("%lld\n",ans);
    return 0;
}
