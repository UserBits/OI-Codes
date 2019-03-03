#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int x[100001],y[100001],s[100001];
inline int ab(int x){
    return x>0?x:-x;
}
inline void qr(int &s){
    s=0;
    register char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    int n,tmp,i;
    long long ans=0;
    qr(n);
    for(i=1;i<=n;++i){
        qr(x[i]),qr(y[i]);
        s[i]=x[i-1]-y[i-1]+s[i-1];
    }
    s[1]=x[n]-y[n]+s[n];
    nth_element(s+1,s+(n+1>>1),s+1+n);
    tmp=s[(n+1)>>1];
    for(i=1;i<=n;++i)
        ans+=ab(s[i]-tmp);
    printf("%lld",ans);
    //system("pause");
    return 0;
}