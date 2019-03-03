#include<iostream>
#include<cstdio>
using namespace std;
int a[10000005];
int main()
{
	int n,p,max=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p);
		a[p]++;
		if(p>max)
			max=p;
	}
	for(int i=0;i<max;i++)
	{
		if(a[i]%2==1)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}

