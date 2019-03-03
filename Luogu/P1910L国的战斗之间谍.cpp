#include <cstdio>
using namespace std;
int f[1005][1005],a[1005],b[1005],c[1005];
inline int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;i++)
      	scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=b[i];j--)
        {
            for(int k=x;k>=c[i];k--)
                f[j][k]=max(f[j][k],f[j-b[i]][k-c[i]]+a[i]);
        }
    }
    printf("%d\n",f[m][x]);
    return 0;
}

