#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005],l,n,k;
inline bool check(int x){
    int cnt=0;
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]>x)
            cnt+=(a[i+1]-a[i]-1)/x;
    }
    return cnt<=k;
}
int main(){
    scanf("%d%d%d",&l,&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int left=0,right=l,mid,ans;
    while(left<=right){
        mid=left+right>>1;
        if(check(mid)){
            ans=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
