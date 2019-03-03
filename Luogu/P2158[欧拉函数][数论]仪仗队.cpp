#include <cstdio>
#include <algorithm>
using namespace std;
int calc(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans=ans*(i-1)/i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        ans=ans*(n-1)/n;
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        puts("0");
        return 0;
    }
    int ans=1;
    for(int i=1;i<n;i++)
        ans+=calc(i)*2;
    printf("%d",ans);
    return 0;
}