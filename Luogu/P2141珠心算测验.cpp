#include<iostream>
#include<cstdio>
using namespace std;
bool p[200005];
int a[105];
int main()
{
	int n,ans=0,temp=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		p[a[i]]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			temp=a[i]+a[j];
			if(p[temp])
			{
				ans++;
				p[temp]=0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
