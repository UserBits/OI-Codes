#include <cstdio>
using namespace std;
const int mod=9901;
int f[205][105],n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=k;i++)
		f[1][i]=1;
    for(int t=1;t<=k;t++)
    {
        for(int i=3;i<=n;i+=2)
        {
            for(int j=1;j<i;j+=2)
            {
                f[i][t]+=f[j][t-1]*f[i-j-1][t-1];
                f[i][t]%=mod;
            }
        }
    }
    printf("%d\n",(f[n][k]-f[n][k-1]+mod)%mod);
    return 0;
}
