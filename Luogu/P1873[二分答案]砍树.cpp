#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005],n,m;
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
inline bool check(int x){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]>x)
            cnt+=a[i]-x;
    }
    return cnt>=m;
}
int main(){
    scanf("%d%d",&n,&m);
    int l=0,r=0,mid,ans;
    for(int i=1;i<=n;i++){
        qr(a[i]);
        r=max(r,a[i]);
    }
    while(l<=r){
        mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
