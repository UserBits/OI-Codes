#include <cstdio>
#include <queue>
using namespace std;
bool p[1005][1005];
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node
{
	int x,y,cost;
};
queue<node> q;
int main()
{
	int n,x1,y1,x2,y2,tx,ty;
	node tmp;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			scanf("%1d",&p[i][j]);
	}
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	q.push((node){x1,y1,0});
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			tx=tmp.x+d[i][0];
			ty=tmp.y+d[i][1];
			if(!p[tx][ty] && tx>=1 && tx<=n && ty>=1 && ty<=n)
			{
				p[tx][ty]=1;
				q.push((node){tx,ty,tmp.cost+1});
				if(tx==x2 && ty==y2)
				{
					printf("%d\n",tmp.cost+1);
					return 0;
				}
			}
		}
	}
}
