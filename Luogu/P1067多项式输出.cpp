#include<iostream>
#include<cstdio>
using namespace std;
int a[105];
int abs(int x)
{
	if(x>=0)
		return x;
	return -x;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=n;i>=0;i--)
		scanf("%d",&a[i]);
	bool p=1;
	for(int i=n;i>=0;i--)
	{
		if(a[i]==0)
			continue;
		if(p==0 && a[i]>0)
			printf("+");
		if(a[i]<0)
			printf("-");
		if(abs(a[i])!=1 || i==0)
			printf("%d",abs(a[i]));
		if(i==0)
			continue;
		printf("x");
		if(i==1)
			continue;
		printf("^%d",i);
		p=0;
	}
	return 0;
}

