#include <cstdio>
#include <cstring>
using namespace std;
int n,b,d,s1[30],s2[30],ans,p[100];
bool check(int t1,int t2)
{
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	int i=0,j=0;
	while(t1)
	{
		s1[i++]=t1&1;
		t1>>=1;
	}
	while(t2)
	{
		s2[j++]=t2&1;
		t2>>=1;
	}
	j=0;
	for(i=0;i<b;i++)
	{
		if(s1[i]!=s2[i])
			j++;
	}
 	return j>=d;
}
bool diff(int t)
{
	for(int i=1;i<=ans;i++)
	{
		if(check(p[i],t)==0)
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&b,&d);
	int maxn=1<<b;
	p[++ans]=0;
	while(ans<n)
	{
		for(int i=p[ans]+1;i<maxn;i++)
		{
			if(diff(i))
			{
				p[++ans]=i;
				break;
			}
		}
	}
	for(int i=1;i<=ans;i++)
	{
		printf("%d",p[i]);
		putchar(i%10==0?'\n':' ');
	}
}
