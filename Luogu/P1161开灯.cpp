#include<iostream>
#include<cstdio>
using namespace std;
bool p[50000005];
int main()
{
	//freopen("light.in","r",stdin);
	//freopen("light.out","w",stdout);
	int n,t,ans=0;
	scanf("%d",&n);
	double a;
	while(n--)
	{
		scanf("%lf%d",&a,&t);
		for(int j=1;j<=t;j++)
			ans^=(int)(j*a);
	}
	printf("%d\n",ans);
	return 0;
}
