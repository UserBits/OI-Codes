#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int size=200005;
int s[size],f[size];
int main()
{
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; i++)
		f[i]=1e8;
	int n=ceil(sqrt(sqrt(m*1.0))+1);
	for(int i=1; i<=n; i++)
		s[i]=i*i*i*i;
	for(int i=1; i<=n; i++)
	{
		for(int j=s[i]; j<=m; j++)
			f[j]=min(f[j],f[j-s[i]]+1);
	}
	printf("%d\n",f[m]);
	return 0;
}

