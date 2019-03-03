#include <cstdio>
using namespace std;
bool p[10000005];
int abs(int x)
{
	if(x>=0)
		return x;
	return -x;
}
int main()
{
	int n,k,temp;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		temp=k;
		scanf("%d",&k);
		p[abs(temp-k)]=1;
	}
	for(int i=1;i<n;i++)
	{
		if(p[i]==0)
		{
			printf("Not jolly\n");
			return 0;
		}
	}
	printf("Jolly\n");
	return 0;
}

