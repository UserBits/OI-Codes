#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N=255;
struct Boot{
    int depth,dis;
}a[N];
int Snow[N],dp[N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&Snow[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&a[i].depth,&a[i].dis);
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=m+1;
        for(int j=i-1;j>0;j--){
            for(int k=dp[j];k<=m;k++){
                if(a[k].depth>=Snow[i] && a[k].depth>=Snow[j] && a[k].dis>=i-j)
                    dp[i]=min(dp[i],k);
            }
        }
    }
    printf("%d\n",dp[n]-1);
    return 0;
}