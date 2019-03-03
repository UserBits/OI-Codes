#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
	int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++)
        printf("%d\n%d\n",a[n-i+1],a[i]);
    if(n%2)
		printf("%d\n",a[n/2+1]);
	return 0;
}

