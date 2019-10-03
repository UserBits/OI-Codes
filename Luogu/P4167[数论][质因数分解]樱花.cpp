#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int p[1000005],pr[500005],s,f[1000005];
const int mod=1e9+7;

void pre(){
    for(int i=2;i<=1000000;i++){
        if(!p[i]){
            p[i]=i;
            pr[++s]=i;
        }
        for(int j=1;j<=s&&i*pr[j]<=1000000;j++){
            if(p[i]<pr[j])
                break;
            p[i*pr[j]]=pr[j];
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    pre();
    for(int i=1;i<=n;i++){
        for(int j=i;j!=1;j/=p[j]){
            f[p[j]]++;
            f[p[j]]%=mod;
        }
    }
    long long ans=1;
    for(int i=1;i<=n;i++)
        ans=ans*((f[i]*2+1)%mod)%mod;
    printf("%lld\n",ans);
    //system("pause");
}