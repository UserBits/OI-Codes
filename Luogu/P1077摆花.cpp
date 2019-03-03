#include <cstdio>
using namespace std;
long long f[105][105],n,m,a[105],low;
const int mod=1000007;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=m;i++)
		f[i][0]=1;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		low=j-a[i];
    		for(int k=j;k>=low;k--)
    		{
				if(k>=0)
				{
					f[i][j]+=f[i-1][k]%mod;
					f[i][j]%=mod;
				}
        		else
					break;
    		}
		}
	}
    printf("%d\n",f[n][m]);
    return 0;
}

