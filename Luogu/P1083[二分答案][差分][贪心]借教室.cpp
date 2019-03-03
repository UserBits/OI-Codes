#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int d[1000005],l[1000005],r[1000005],s[1000005],tmp[1000005],n,m;
inline void qr(int &s){
    s=0;
    register char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
inline bool check(int x){
    int i,sum=0;
    for(i=1;i<=n;++i)
        tmp[i]=0;
    for(i=1;i<=x;++i){
        tmp[l[i]]+=d[i];
        tmp[r[i]+1]-=d[i];
    }
    for(i=1;i<=n;++i){
        sum+=tmp[i];
        if(sum>s[i])
            return 0;
    }
    return 1;
}
int main(){
    qr(n);  qr(m);
    int i;
    for(i=1;i<=n;++i)
        qr(s[i]);
    for(i=1;i<=m;++i)
        qr(d[i]),qr(l[i]),qr(r[i]);
    if(check(m)){
        puts("0");
        return 0;
    }
    int left=0,right=m,mid;
    while(left<=right){
        mid=(left+right)>>1;
        if(check(mid))
            left=mid+1;
        else
            right=mid-1;
    }
    printf("-1\n%d\n",left);
    //system("pause");
    return 0;
}