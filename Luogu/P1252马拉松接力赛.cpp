#include <cstdio>
using namespace std;
int a[10][20],t[10][20],ans[10];
int main()
{
	int minn,flag,sum=0;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=10;j++)
		{
			scanf("%d",&a[i][j]);
			t[i][j]=a[i][j]-a[i][j-1];
		}
	}
	for(int i=1;i<=5;i++)
		ans[i]=1;
	for(int i=0;i<20;i++)
	{
		minn=1<<30;
		for(int j=1;j<=5;j++)
		{
			if(t[j][ans[j]+1]<minn && ans[j]<10)
			{
				flag=j;
				minn=t[j][ans[j]+1];
			}
		}
		ans[flag]++;
	}
	for(int i=1;i<=5;i++)
		sum+=a[i][ans[i]];
	printf("%d\n",sum);
	for(int i=1;i<=5;i++)
		printf("%d ",ans[i]);
	return 0;
}
