#include <cstdio>
#include <cstdlib>
inline int mn(int x,int y){
    return x<y?x:y;
}
int sum[5005],dp[5005];
//dp[i]表示以i开头时候最佳拿法所获得的值
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&sum[i]);
        dp[i]=sum[i];
        sum[i]+=sum[i-1];
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n;i++){
            int j=i+l-1;
            if(j>n)
                break;
            dp[i]=sum[j]-sum[i-1]-mn(dp[i],dp[i+1]);
        }
    }
    printf("%d\n",dp[1]);
    //system("pause");
    return 0;
}