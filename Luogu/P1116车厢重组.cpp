#include<cstdio>
int main()
{
	int a[10001],n,s=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			if(a[i]>a[j])
				s++;
		}
	}
	printf("%d\n",s);
	return 0;
}
