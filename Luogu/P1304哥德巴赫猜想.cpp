#include<iostream>
#include<cstdio>
using namespace std;
bool prime(int x)
{
	if(x<2)
		return 0;
	if(x==2)
		return 1;
	if(x%2==0)
		return 0;
	for(int k=3;k*k<=x;k+=2)
	{
		if(x%k==0)
			return 0;
	}
	return 1;
}
int main()
{
	int a,b;
	scanf("%d",&b);
	a=4;
	b-=b%2;
	for(int i=a;i<=b;i+=2)
	{
		for(int j=2;;j++)
		{
			if(prime(j) && prime(i-j))
			{
				printf("%d=%d+%d\n",i,j,i-j);
				break;
			}
		}
	}
	return 0;
}
