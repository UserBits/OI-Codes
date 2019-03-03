#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N=105;
int a[N],dp[N][N],s[N][N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=n+1;i++){
        for(int j=i+1;j<=n+1;j++){
            for(int k=i+1;k<j;k++){
                if(!i)
                    s[i+1][j-1]+=abs(2*(a[k]-a[j])); //i<s1
                else if(j==n+1)
                    s[i+1][j-1]+=abs(2*(a[k]-a[i])); //i>sk
                else
                    s[i+1][j-1]+=abs(2*a[k]-a[i]-a[j]); // s1<=i<=sk
            }
        }
    }
    memset(dp,0x7f,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(dp[i][j]<=m){
                for(int k=i+1;k<=n+1;k++)
                    dp[k][j+1]=min(dp[k][j+1],dp[i][j]+s[i+1][k-1]);
            }
        }
    }
    for(int i=2;i<=n+1;i++){
        if(dp[n+1][i]<=m){
            printf("%d %d\n",i-1,dp[n+1][i]);
            return 0;
        }
    }
    return 0;
}
