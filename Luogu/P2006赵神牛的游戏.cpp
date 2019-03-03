#include <cstdio>
using namespace std;
int main()
{
	int k,m,n,x,y;
	bool p=0;
	scanf("%d%d%d",&k,&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(x!=0)
		{
			if(k/x*y>=n)
			{
				printf("%d ",i);
				p=1;
			}
		}
		else if(x==0 && y!=0)
		{
			printf("%d ",i);
			p=1;
		}
	}
	if(p==0)
		printf("-1\n");
	return 0;
}
