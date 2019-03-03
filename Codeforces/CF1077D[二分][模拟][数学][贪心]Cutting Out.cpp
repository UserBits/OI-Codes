#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N=200005;
int n,k,a[N],num[N],res[N],tot;
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
inline bool check(int x){
    int s=0;
    for(int i=1;i<=tot;i++)
        s+=num[i]/x;
    return s>=k;
}
int main(){
    qr(n);  qr(k);
    for(int i=1;i<=n;i++)
        qr(a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1])
            num[tot]++;
        else
            num[++tot]=1;
    }
    tot=unique(a+1,a+1+n)-a-1;
    int left=1,right=n,mid,ans;
    while(left<=right){
        mid=left+right>>1;
        if(check(mid)){
            ans=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    int cnt=0;
    for(int i=1;i<=tot;i++){
        while(num[i]>=ans){
            res[++cnt]=a[i];
            num[i]-=ans;
        }
    }
    for(int i=1;i<=k;i++)
        printf("%d ",res[i]);
    puts("");
    return 0;
}