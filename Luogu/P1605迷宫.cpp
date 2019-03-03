#include <cstdio>
using namespace std;
int n,m,sx,sy,fx,fy,ans=0;
bool a[6][6];
void f(int x,int y)
{
	if(x==fx && y==fy)ans++;
	else
	{
		a[x][y]=1;
		if(x-1>0 && !a[x-1][y])
			f(x-1,y);
		if(x+1<=n && !a[x+1][y])
			f(x+1,y);
		if(y-1>0 && !a[x][y-1])
			f(x,y-1);
		if(y+1<=m && !a[x][y+1])
			f(x,y+1);
		a[x][y]=0;
	}
}
int main()
{
	int t;
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
	for(int i=1,a1,b; i<=t; i++)
	{
		scanf("%d%d",&a1,&b);
		a[a1][b]=1;
	}
	f(sx,sy);
	printf("%d\n",ans);
	return 0;
}

