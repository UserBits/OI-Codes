#include <cstdio>
using namespace std;
char a[105][105];
int dx[8]={1,1,1,0,0,-1,-1,-1},dy[8]={1,0,-1,1,-1,1,0,-1},n,m;
inline void dfs(int i,int j)
{
	a[i][j]='.';
	int tx,ty;
	bool p=0;
	for(int t=0;t<9;t++)
	{
		tx=i+dx[t];
		ty=j+dy[t];
		if(tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]=='W')
		{
			dfs(tx,ty);
			p=1;
		}
	}
	if(p==0)
		return;
}
int main()
{
	int ans=0;
	char tmp;
	scanf("%d%d\n",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;)
		{
			tmp=getchar();
			if(tmp!=' ' && tmp!='\n')
				a[i][j++]=tmp;
		}
	}
	/*
	putchar('\n');
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			putchar(a[i][j]);
		putchar('\n');
	}
	*/
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='W')
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

