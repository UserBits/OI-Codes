#include <cstdio>
using namespace std;
int p[20][20],a,b,ans;
inline void dfs(int i,int j)
{
	if(i==a && j==b)
	{
		ans++;
		return;
	}
	if(p[i][j])
		return;
	if(i+1<=a && !p[i+1][j])
		dfs(i+1,j);
	if(j+1<=b && !p[i][j+1])
		dfs(i,j+1);
}
int main()
{
	scanf("%d%d",&a,&b);
	int n,x,y;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		p[x][y]=1;
	}
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}

