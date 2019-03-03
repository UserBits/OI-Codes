#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int t,k,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		s=(int)sqrt(k*2.0);
		if((s*s+s)/2+1==k || ((s-1)*(s-1)+s-1)/2+1==k)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
