// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <cstdlib>
int n;
const int mod=1e9+7;
struct node{
    long long a[105][105];
    node(){
        memset(a,0,sizeof(a));
    }
};
node multi(node x,node y){
    node r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++)
                r.a[i][j]=(r.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
        }
    }
    return r;
}
node ksm(node x,long long y){
    node r;
    for(int i=1;i<=n;i++)
        r.a[i][i]=1;
    while(y){
        if(y&1)
            r=multi(r,x);
        y>>=1;
        x=multi(x,x);
    }
    return r;
}
int main(){
    long long k;
    scanf("%d%lld",&n,&k);
    node tmp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&tmp.a[i][j]);
    }
    node ans=ksm(tmp,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%lld ",ans.a[i][j]);
        puts("");
    }
    return 0;
}