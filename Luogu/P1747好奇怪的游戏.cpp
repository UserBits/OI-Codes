#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
bool p[25][25];
int d[12][2]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1,2,2,2,-2,-2,2,-2,-2};
struct node
{
	int x,y,cost;
};
queue<node> q;
inline void bfs(int lx,int ly)
{
	node tmp;
	int tx,ty;
	q.push((node){lx,ly,0});
	p[lx][ly]=1;
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		for(int i=0;i<12;i++)
		{
			tx=tmp.x+d[i][0];
			ty=tmp.y+d[i][1];
			if(tx>=1 && tx<=20 && ty>=1 && ty<=20 && !p[tx][ty])
			{
				p[tx][ty]=1;
				q.push((node){tx,ty,tmp.cost+1});
				if(tx==1 && ty==1)
				{
					printf("%d\n",tmp.cost+1);
					return;
				}
			}
		}
	}
}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	bfs(x,y);
	memset(p,0,sizeof(p));
	while(!q.empty())
		q.pop();
	scanf("%d%d",&x,&y);
	bfs(x,y);
	return 0;
}
