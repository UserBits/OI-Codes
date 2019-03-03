/*
	this is not a correct code.
	please change it.
	1.use "freopen(...)";
	2.test it;
	3.change the file name.
*/
#include <cstdio>
using namespace std;
int a[25],b;
int change(int n)
{
	int i=0,j;
	while (n>0)
	{
		a[++i]=n%b;
		n/=b;
	}
	return i;
}
bool function(int k)
{
	int i=1,j=k;
	while (i<j)
	{
		if (a[i++]!=a[j--])
			return 0;
	}
	return 1;
}
void print(int num)
{
	int k[25],i=0,j;
	while (num>0)
	{
		k[++i]=num%b;
		num/=b;
	}
	for (j=i; j>=1; j--)
	{
		if (k[j]>=10)
			printf("%c",k[j]-10+'A');
		else
			printf("%d",k[j]);
	}
	printf(" ");
}
void work()
{
	int i,j,n;
	for (i=1; i<=300; i++)
	{
		n=change(i*i);
		if (function(n))
		{
			print(i);
			for (j=n; j>=1; j--)
			{
				if (a[j]>=10)
					printf("%c",a[j]-10+'A');
				else
					printf("%d",a[j]);
			}
			printf("\n");
		}
	}
}
int main()
{
	scanf("%d",&b);
	work();
	return 0;
}

