#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct loc
{
	int x,y;
}tmp,first;
inline int abs(int x)
{
	return x>0?x:-x;
}
const int dx[4]={1,-1,2,-2},dy[4]={1,-1,2,-2};
int a[405][405],n,m;
bool p[405][405];
void bfs(int x,int y,int step)
{
	a[x][y]=step;
	p[x][y]=0;
	queue<loc> q;
	int i,j,nx,ny;
	tmp.x=x;
	tmp.y=y;
	q.push(tmp);
	while(!q.empty())
	{
		first=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(abs(dx[i])!=abs(dy[j]))
				{
					nx=first.x+dx[i];
					ny=first.y+dy[j];
					if(nx<1 || nx>n || ny<1 || ny>m)
						continue;
					if(p[nx][ny]==1)
					{
						tmp.x=nx;
						tmp.y=ny;
						q.push(tmp);
						p[nx][ny]=0;
						a[nx][ny]=a[first.x][first.y]+1;
					}
				}
			}
		}
	}
}
int main()
{
	memset(p,1,sizeof(p));
	memset(a,-1,sizeof(a));
	int x,y,i,j;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	bfs(x,y,0);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			printf("%-5d",a[i][j]);
		printf("\n");
	}
	return 0;
}

