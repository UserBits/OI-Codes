#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[30005];
int main()
{
	int w,n,ans=0;
	scanf("%d%d",&w,&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int l=0,r=n-1;
	while(l<=r)
	{
		if(a[l]+a[r]<=w)
		{
			l++;
			r--;
			ans++;
		}
		else
		{
			r--;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

