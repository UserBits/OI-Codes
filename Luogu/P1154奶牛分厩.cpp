#include <cstdio>
#include <cmath>
using namespace std;
const int size=1000005;
int n,i,j,a[size],b[size],c[size];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			b[i]=abs(a[i]-a[j]);
			c[b[i]]++;
		}
	}
	for(i=n;i<=1000000;i++)
	{
		if(c[i]==0)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
