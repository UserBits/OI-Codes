#include <cstdio>
using namespace std;
long long a[50];
int main()
{
	long long k;
	scanf("%lld",&k);
	a[0]=0;
	a[1]=1;
	for(int i=2; i<48; i++)
		a[i]=a[i-1]+a[i-2];
	for(int i=0; i<48; i++)
	{
		if(a[i]+a[i+1]>=k)
		{
			printf("m=%d\nn=%d\n",a[i],a[i+1]);
			return 0;
		}
	}
	return 0;
}
