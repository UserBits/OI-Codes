#include <cstdio>
#include <iostream>
using namespace std;
char a[105][105];
bool p[105][105];
int dx[4]= {1,0,-1,0},dy[4]= {0,1,0,-1},n,m;
void dfs(int i,int j)
{
	int tx,ty;
	for (int k=0; k<4; k++)
	{
		tx=i+dx[k];
		ty=j+dy[k];
		if(tx>=0 && ty>=0 && tx<n && ty<m && p[tx][ty]==0 && a[tx][ty]!='0')
		{
			p[tx][ty]=1;
			dfs(tx,ty);
		}
	}
}
int main()
{
	int ans=0;
	char tmp;
	scanf("%d%d\n",&n,&m);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cin>>a[i][j];
			//tmp=getchar();
			//if(tmp!=' ' && tmp!='\n')
				//a[i][j++]=tmp;
		}
	}
	/*
	for(int i=0;i<105;i++)
	{
		for(int j=0;j<105;j++)
			putchar(p[i][j]+'0');
		putchar('\n');
	}
	*/
	/*
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
			putchar(a[i][j]);
		putchar('\n');
	}
	*/
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (a[i][j]!='0' && p[i][j]==0)
			{
				ans++;
				p[i][j]=1;
				dfs(i,j);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
