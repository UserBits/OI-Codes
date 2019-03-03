#include <cstdio>
#include <cstring>
using namespace std;
int solve(int a)
{
	int sum=a;
	while(a)
	{
		sum+=a%10;
		a/=10;
	}
	return sum;
}
int SN[10000100],n,k,s,NSN;
bool bucket[10000100];
int main()
{
	int t=1;
	memset(bucket,true,sizeof(bucket));
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++)
	{
		NSN=solve(i);
		bucket[NSN]=false;
		if (bucket[i])
			SN[t++]=i;
	}
	printf("%d\n",t-1);
	for (int i=0; i<k; i++)
	{
		scanf("%d",&s);
		printf("%d ",SN[s]);
	}
	printf("\n");
	return 0;
}
