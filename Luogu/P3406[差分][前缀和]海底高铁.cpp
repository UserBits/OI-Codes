#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int sum[100005],p[100005];
template<typename r_e_a_d>
inline void qr(r_e_a_d &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    int n,m;
    qr(n);  qr(m);
    for(int i=1;i<=m;i++)
        qr(p[i]);
    for(int i=1;i<m;i++){
        //p[i]与p[i+1]为两个端点
        sum[min(p[i],p[i+1])]++; //差分
        sum[max(p[i],p[i+1])]--; //这里不需要+1
    }
    long long ans=0,cnt=0,a,b,c;
    for(int i=1;i<n;i++){
        cnt+=sum[i];
        qr(a);  qr(b);  qr(c);
        ans+=min(cnt*a,cnt*b+c);
    }
    printf("%lld\n",ans);
    //system("pause");
    return 0;
}