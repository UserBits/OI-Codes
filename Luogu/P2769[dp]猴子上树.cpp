#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a[5005],b[5005],n,m,i,j;
long long f[2][5005];
int main(){
    //freopen("testdata.in","r",stdin);
    //freopen("testdata.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    for(i=0;i<=1;i++){
        for(j=0;j<=m;j++)
            f[i][j]=1ll<<60;
    }
    f[1][1]=abs(a[1]-b[1]);
    for(i=2;i<=n;i++){
        for(j=1;j<=m&&j<=i;j++){
            f[i&1][j]=min(f[(i-1)&1][j],f[(i-1)&1][j-1])+abs(a[i]-b[j]);
        }
    }
    printf("%lld\n",f[n&1][m]);
    return 0;
}