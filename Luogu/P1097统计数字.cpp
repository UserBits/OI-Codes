#include<cstdio>
#include<algorithm>
using namespace std;
int a[200005];
int main()
{
	int n,ans=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		if(a[i-1]==a[i])
			ans++;
		else
		{
			printf("%d %d\n",a[i-1],ans);
			ans=1;
		}
	}
	printf("%d %d\n",a[n-1],ans);
	return 0;
}

