#include <cstdio>
int vis[50][50]= {0},n,array[50]= {0},sum=0;
void dfs(int cur)
{
	if(cur==n)
	{
		if(sum<3)
		{
			for(int j=0; j<n; j++)
				printf("%d ",array[j]+1);
			printf("\n");
		}
		sum++;
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n])
			{
				array[cur]=i;
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
				dfs(cur+1);
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(0);
	printf("%d\n",sum);
	return 0;
}
