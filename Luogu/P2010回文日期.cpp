#include<iostream>
#include<cstdio>
using namespace std;
int s[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<13;i++)
	{
		for(int j=1;j<=s[i];j++)
		{
			int d=j%10*1000+j/10*100+i%10*10+i/10;
			int sum=d*10000+i*100+j;
			if(!(sum<n || sum>m))
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

