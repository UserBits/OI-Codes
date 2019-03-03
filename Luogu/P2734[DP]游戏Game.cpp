#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[101],dp[101],s[101];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        dp[i]=a[i];
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n;i++){
            int j=i+l-1;
            if(j>n)
                break;
            dp[i]=s[j]-s[i-1]-min(dp[i],dp[i+1]);
        }
    }
    printf("%d %d\n",dp[1],s[n]-dp[1]);
    //system("pause");
    return 0;
}