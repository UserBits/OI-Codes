#include <cstdio>
using namespace std;
const int dx[4]={2,1,-1,-2},dy[4]={1,2,2,1};
int n,m,ans=0;
inline void input(int &s)
{
	char c=getchar();
	int num=0,f=1;
	for(;c<'0' || c>'9';c=getchar())
	{
		if(c=='-')
			f=-1;
	}
	for(;c>='0' && c<='9';c=getchar())
		num=(num<<1)+(num<<3)+(c-'0');
	s=num*f;
}
inline void output(int s)
{
	char tmp[12];
	int i=0;
	bool negative=0;
	if(s<0)
	{
		negative=1;
		s=-s;
	}
	while(s)
	{
		tmp[i++]=s%10+'0';
		s/=10;
	}
	if(negative)
		putchar('-');
	while(i--)
		putchar(tmp[i]);
}
void dfs(int x,int y)
{
	if(x==n && y==m)
		ans++;
	if(x>n || y>m ||x<0)
		return;
	int xi,yi,i;
	for(i=0;i<4;i++)
	{
		xi=x+dx[i];
		yi=y+dy[i];
			dfs(xi,yi);
	}
}
int main()
{
	input(n);
	input(m);
	dfs(0,0);
	output(ans);
	return 0;
}
