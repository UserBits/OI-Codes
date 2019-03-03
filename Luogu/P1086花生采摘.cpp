#include <cstdio>
using namespace std;
int a[505][25],total,time,x,y;
int abs(int x)
{
	if(x<0)
		return -x;
	return x;
}
int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			scanf("%d",&a[i][j]);
	int maxn,bx,by;
	while(time<=k)
	{
		bool flag=false;
		maxn=-1<<30,bx=0,by=0;
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
			{
				if(maxn<a[i][j])
				{
					maxn=a[i][j];
					bx=i,by=j;
				}
			}
		if(!x && !y)
			y=by;
		int t=abs(bx-x)+abs(by-y)+1;
		if(time+t>k)
			break;
		if(time+t+bx>k)
			break;
		time+=t;
		x=bx,y=by;
		total+=maxn;
		a[x][y]=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				if(a[i][j]) flag=true;
		if(!flag) break;
	}
	printf("%d",total);
	return 0;
}

