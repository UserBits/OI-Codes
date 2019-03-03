#include<iostream>
#include<cstdio>
int num(int n)
{
	int sum=0;
	for(int j=1;2*j<=n;j++)
	{
		if(n%j==0)
			sum+=j;
	}
	return sum;
}
int main()
{
	int s,x,y,i;
	scanf("%d",&s);
	for(i=s;;i++)
	{
		x=num(i);
		y=num(x);
		if(i!=x && i==y)
		{
			printf("%d %d\n",i,x);
			break;
		}
	}
	return 0;
}
