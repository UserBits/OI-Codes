#include <cstdio>
using namespace std;
int p[10005];
int main()
{
	int l,n,t,x,y,a=0,b=0;
	scanf("%d%d",&l,&n);
	while(n--)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(t==0)
		{
			for(int i=x;i<=y;i++)
			{
				if(p[i]==2)
					a++;
				p[i]=1;
			}
		}
		else
		{
			for(int i=x;i<=y;i++)
			{
				if(p[i]==1)
					p[i]=2;
			}
		}
	}
	for(int i=0;i<=l;i++)
	{
		if(p[i]==2)
			b++;
	}
	printf("%d\n%d\n",b,a);
	return 0;
}

