#include<iostream>
#include<cstdio>
using namespace std;
int cnt[135][135],n,d;
void work()
{
	for(int i=0;i<135;i++)
	{
		for(int j=0;j<135;j++)
			cnt[i][j]=0;
	}
	scanf("%d%d",&d,&n);
	int x,y,len;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&len);
		for(int xr=-d;xr<=d;xr++)
		{
			if(x+xr>=0 && x+xr<129)
			{
				for(int yr=-d;yr<=d;yr++)
				{
					if(y+yr>=0 && y+yr<129)
						cnt[x+xr][y+yr]+=len;
				}
			}
		}
	}
	int max=-1,num=0;
	for(int i=0;i<129;i++)
	{
		for(int j=0;j<129;j++)
		{
			if(cnt[i][j]>max)
			{
				max=cnt[i][j];
				num=1;
			}
			else if(cnt[i][j]==max)
				num++;
		}
	}
	printf("%d %d\n",num,max);
}
int main()
{
	work();
	return 0;
}
