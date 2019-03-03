#include<iostream>
#include<cstdio>
using namespace std;
int a[10005];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<n;i++)
	{
		bool p=0;
		if(a[i]<a[i-1])
		{
			while(a[i]==a[i+1])
			{
				p=1;
				i++;
			}
		}
		if(a[i]<a[i+1] && p)
			ans++;
		if((a[i]<a[i-1]) && (a[i]<a[i+1]))
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
