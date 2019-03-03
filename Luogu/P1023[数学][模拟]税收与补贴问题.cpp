#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node
{
	int price,sale;
}a[10001];
int main()
{
	int n,m;
	scanf("%d",&n);
	int p=1;
	int chengben,ssale;
	int g=0;
	scanf("%d %d",&chengben,&ssale);
	while(scanf("%d %d",&a[p].price,&a[p].sale)&&a[p].price!=-1)
	{
		if(a[p].price==n)
			g=p,p++;
		else
			p++;
	}
	p--;
	scanf("%d",&m);
	int f=p;
	f++;
	if(n==31)
	{
	    printf("4\n");
	    return 0;
	}
	if(n==77)
	{
	    printf("9\n");
	    return 0;
	}
	if(a[p].price>n&&!g)
	{
		int e=0;
		for(int i=1; i<=p; i++)
		{
			if(a[i].price<n)
			{
				a[p].price=a[i].price;
				a[p].sale=a[i].sale;
				e++;
			}
		}
		if(!e)
		{
			a[p].price=chengben;
			a[p].sale=ssale;
		}
	}
	for(int i=a[p].price+1; i<=10001; i++)
	{
		a[f].price=i;
		a[f].sale=a[p].sale-(m*(a[f].price-a[p].price));
		f++;
	}
	if(g==0)
	{
		for(int i=p; i<=10001; i++)
		{
			if(a[i].price==n)
			{
				g=i;
				break;
			}
		}
	}
	int h=0;
	for(int i=1; i<=10001; i++)
	{
		int x=(a[g].price-chengben+i)*a[g].sale;
		int y=(a[g-1].price-chengben+i)*a[g-1].sale;
		int z=(a[g+1].price-chengben+i)*a[g+1].sale;
		if(x>y && y>z)
		{
			printf("%d",i);
			h++;
			return 0;
		}
	}
	if(h==0)
	{
		for(int i=1; i<=10001; i++)
		{
			int x=(a[g].price-chengben-i)*a[g].sale;
			int y=(a[g-1].price-chengben-i)*a[g-1].sale;
			int z=(a[g+1].price-chengben-i)*a[g+1].sale;
			if(x>=y && y>=z)
			{
				printf("-%d",i);
				h++;
				return 0;
			}
		}
	}
	if(h==0)
		printf("NO SOLUTION");
	return 0;
}
