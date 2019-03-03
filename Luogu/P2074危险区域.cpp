#include <cstdio>
#include <cmath>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
double dis(int x,int y,int a,int b)
{
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
int m,n,k,t,maxn,ans,c,d;
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&t);
	while(k--)
	{
		scanf("%d%d",&c,&d);
		ans=0;
		for(int i=max(1,c-t); i<=min(n,c+t); i++)
		{
			for(int j=max(1,d-t); j<=min(m,d+t); j++)
			{
				if(dis(i,j,c,d)<=t)
					ans++;
			}
		}
		if(ans>maxn)
			maxn=ans;
	}
	printf("%d",maxn);
	return 0;
}
