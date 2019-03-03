#include <cstdio>
#include <cstdlib>
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int q_pow(int x,int y,int mod){
    int r=1;
    while(y){
        if(y&1)
            r=r*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return r;
}
int main(){
    int n,m,k,x;
    scanf("%d%d%d%d",&n,&m,&k,&x);
    int mod=n/gcd(n,m); //完整的圈数
    int cnt=q_pow(10,k,mod);    //取模后是剩余的不完整的圈数;
    while(cnt--)
        x=(x+m)%n;
    printf("%d\n",x);
    //system("pause");
    return 0;
}