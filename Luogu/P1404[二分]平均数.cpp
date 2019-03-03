#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[100005],n,m;
long long s[100005];
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
inline bool check(int x){
    long long mn=1ll<<60;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i]-x;
        if(i>=m){
            mn=min(mn,s[i-m]);
            if(s[i]>=mn)
                return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    int l=0,r=0,mid,ans;
    for(int i=1;i<=n;i++){
        qr(a[i]);
        a[i]=a[i]*10000;
        r=max(r,a[i]);
    }
    //printf("%d %d\n",l,r);
    while(l<=r){
        mid=l+r>>1;
        //printf("[%d]\n",check(mid));
        if(check(mid)){
            ans=mid;
            l=mid+1;
        } 
        else
            r=mid-1;
    }
    printf("%d\n",ans/10);
    //system("pause");
    return 0;
}