#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005],sum[1005],f[1005][1005];
inline void qr(int &s)
{
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+(c-'0');
}
int main()
{
    int p,q;
    scanf("%d%d",&p,&q);
    for(int i=1;i<=q;i++)
        scanf("%d",&a[i]);
    a[0]=0;
    a[++q]=p+1;
    sort(a,a+1+q);
    for(int i=1;i<=q;i++)
        sum[i]=a[i]-a[i-1]-1+sum[i-1];
    int j,tp;
    for(register int l=2;l<=q;l++)
    {
        for(register int i=1;i<=q;i++)
        {
            j=i+l-1;
            if(j>q)
                break;
            for(int k=i;k<j;k++)
            {
                tp=f[i][k]+f[k+1][j]+sum[j]-sum[i-1]+j-i-1;
                if(!f[i][j] || tp<f[i][j])
                    f[i][j]=tp;
            }
        }
    }
    printf("%d\n",f[1][q]);
    return 0;
}
