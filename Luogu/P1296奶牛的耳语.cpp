#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	int n,d,ans=0;
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((a[j]-a[i])<=d)
				ans++;
			else
				break;
		}
	}
	printf("%d\n",ans);
	return 0;
}

