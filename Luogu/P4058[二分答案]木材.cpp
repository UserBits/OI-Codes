#include <cstdio>
#include <iostream>
using namespace std;
template<typename r_e_a_d>
inline void qr(r_e_a_d &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=s*10+c-'0';
}
unsigned long long s,l,h[200005],a[200005];
int n;
inline bool check(unsigned long long x){
    unsigned long long cnt=0;
    for(int i=0;i<n;i++){
        if(h[i]+x*a[i]>=l)
            cnt+=h[i]+x*a[i];
        if(cnt>=s)
            break;
    }
    return cnt>=s;
}
int main(){
    qr(n);  qr(s);  qr(l);
    for(int i=0;i<n;i++)
        qr(h[i]);
    for(int i=0;i<n;i++)
        qr(a[i]);
    unsigned long long sum=0,left=0,right=1e18,mid,ans;
    for(int i=0;i<n;i++){
        if(h[i]>=l)
            sum+=h[i];
    }
    if(sum>=s){
        puts("0");
        return 0;
    }
    while(left<=right){
        mid=left+right>>1;
        if(check(mid)){
            ans=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    cout<<ans<<endl;
}
