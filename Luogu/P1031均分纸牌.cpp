#include<iostream>
#include<cstdio>
using namespace std;
int a[105];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,ans=0,sum=0,ave,last=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ave=sum/n;
	for(int i=1;i<=n-1;i++)
	{
		if(a[i]==ave)
			continue;
		ans++;
		if(a[i]>ave)
		{
			a[i+1]+=a[i]-ave;
			a[i]=ave;
		}
		if(a[i]<ave)
		{
			a[i+1]-=ave-a[i];
			a[i]=ave;
		}
	}
	printf("%d\n",ans);
	return 0;
}

