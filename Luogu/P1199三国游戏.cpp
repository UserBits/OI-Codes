#include<algorithm>
#include<cstdio>
using namespace std;
int a[509][509],n,b[509],f[509];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            b[j]=a[i][j];
        sort(b+1,b+n+1);
        f[i]=b[n-1];
    }
    sort(f+1,f+n+1);
    printf("1\n%d",f[n]);
    return 0;
}
