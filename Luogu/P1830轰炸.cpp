#include<iostream>
#include<cstdio>
using namespace std;
int x1[5005],y1[5005],x2[5005],y2[5005];
int main()
{
	int n,m,x,y,askx,asky;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=x;i++)
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	int ans=0,last=0;
	for(int i=1;i<=y;i++)
	{
		ans=0;
		scanf("%d%d",&askx,&asky);
		for(int j=1;j<=x;j++)
		{
			if(askx>=x1[j] && askx<=x2[j])
			{
				if(asky>=y1[j] && asky<=y2[j])
				{
					ans++;
					last=j;
				}
			}
		}
		if(!ans)
			printf("N\n");
		else
			printf("Y %d %d\n",ans,last);
	}
	return 0;
}

