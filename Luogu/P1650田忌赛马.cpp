#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=2005;
int a[maxn],b[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1; i<=n; i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int l1=1,r1=n,l2=1,r2=n,res=0;
	while (l1<=r1)
	{
		if (a[l1]>b[l2])
		{
			res+=200;
			l1++;
			l2++;
		}
		else if (a[r1]>b[r2])
		{
			res+=200;
			r1--;
			r2--;
		}
		else
		{
			if (a[l1]==b[r2])
				res+=200;
			res-=200;
			l1++;
			r2--;
		}
	}
	printf("%d\n",max(res,0));
	return 0;
}
