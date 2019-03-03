#include<cstdio>
#define maxlen 32768
#define maxG 15
#define maxV 25
int que[maxlen+1][maxV+1],b[maxlen+1],c[maxlen+1],s[maxV+1],a[maxG+1][maxV+1],g[maxG+1],V,G,ans;
int check(int x)
{
	for(int j=1; j<=V; j++)
		if(que[x][j]<s[j]) return 0;
	return 1;
}
void count(int n,int x)
{
	while(n)
	{
		g[n--]=que[x][0];
		x=b[x];
	}
}
void bfs()
{
	int head=-1,tail=0;
	while(head!=tail)
	{
		head++;
		for(int i=que[head][0]+1; i<=G; i++)
		{
			tail++;
			b[tail]=head,c[tail]=c[head]+1;
			que[tail][0]=i;
			for(int j=1; j<=V; j++) que[tail][j]=que[head][j]+a[i][j];
			if(check(tail))
			{
				ans=c[tail];
				count(ans,tail);
				return;
			}
		}
	}
}
void read()
{
	scanf("%d",&V);
	for(int i=1; i<=V; i++) scanf("%d",&s[i]);
	scanf("%d",&G);
	for(int i=1; i<=G; i++)
		for(int j=1; j<=V; j++) scanf("%d",&a[i][j]);
}
void work()
{
	bfs();
}
void write()
{
	printf("%d ",ans);
	for(int i=1; i<ans; i++) printf("%d ",g[i]);
	printf("%d",g[ans]);
}
int main()
{
	read();
	work();
	write();
	return 0;
}
