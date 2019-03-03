#include <cstdio>
#include <cstring>
using namespace std;
struct hp
{
	int s[210];
} n,a,b,ans;
char N[110];
int k,now,tmp;
void mult1(hp a,hp b,hp &c,int d)
{
	hp s;
	memset(s.s,0,sizeof(s.s));
	for(int i=1; i<=d; i++)
		for(int j=1; j<=d; j++)
			s.s[i+j-1]+=a.s[i]*b.s[j];
	for(int i=1; i<=d+1; i++)
		if (s.s[i]>=10)
		{
			s.s[i+1]+=s.s[i]/10;
			s.s[i]%=10;
		}
	c=s;
}
void mult2(hp a,int b,hp &c)
{
	hp s;
	memset(s.s,0,sizeof(s.s));
	for(int i=1; i<=200; i++)
		s.s[i]+=a.s[i]*b;
	for(int i=1; i<=200; i++)
		if (s.s[i]>=10)
		{
			s.s[i+1]+=s.s[i]/10;
			s.s[i]%=10;
		}
	c=s;
}
int main()
{
	scanf("%s%d",N,&k);
	for(int i=strlen(N)-1,j=1; i>=0; i--,j++)
		n.s[j]=N[i]-'0';
	ans.s[1]=1;
	a=n;
	for(now=1; now<=k; now++)
	{
		b=n;
		tmp=b.s[now];
		int len=0;
		do
		{
			mult1(a,b,b,k);
			len++;
		}
		while(len<10 && b.s[now]!=tmp);
		if(b.s[now]!=tmp)
		{
			printf("-1");
			return 0;
		}
		b=a;
		for(int i=1; i<=len-1; i++)
			mult1(a,b,a,k);
		mult2(ans,len,ans);
	}
	int out;
	for(out=200; ans.s[out]==0; out--);
	for(; out>=1; out--)
		printf("%d",ans.s[out]);
	return 0;
}
