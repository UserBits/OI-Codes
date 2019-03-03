#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
struct node{
    int h,w;
    friend bool operator < (node x,node y){
        return x.h<y.h;
    }
}a[105];
int f[105][105];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].h,&a[i].w);
    sort(a+1,a+1+n);
    memset(f,0x7f,sizeof(f));
    for(int i=0;i<=n;i++)
        f[i][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=j-1;k<i;k++)
                f[i][j]=min(f[i][j],f[k][j-1]+abs(a[i].w-a[k].w));
        }
    }
    int ans=2e9;
    for(int i=n-k;i<=n;i++)
        ans=min(ans,f[i][n-k]);
    printf("%d\n",ans);
    return 0;
}