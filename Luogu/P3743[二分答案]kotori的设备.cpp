#include <cstdio>
#include <iostream>
using namespace std;
int n;
double p,a[200005],b[200005];
inline bool check(double x){
    double cnt=0.0,sum=p*x;
    for(int i=1;i<=n;i++){
        if(a[i]*x<=b[i])
            continue;
        cnt+=(a[i]*x-b[i]);
    }
    return cnt<=sum;
}
int main(){
    double left=0.0,right=10000000000.0,mid,ans,sum=0.0;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    if(sum<=p){
        puts("-1.00000000");
        return 0;
    }
    while(right-left>1e-6){
        mid=(left+right)/2.0;
        if(check(mid)){
            ans=mid;
            left=mid;
        }
        else
            right=mid;
    }
    cout<<ans<<endl;
    return 0;
}
