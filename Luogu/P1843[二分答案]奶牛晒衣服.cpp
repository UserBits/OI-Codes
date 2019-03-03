#include <cstdio>
#include <cstdlib>
using namespace std;
int x[500005],n,a,b;
bool check(int m){
    int s=0,tmp;
    for(int i=1;i<=n;i++){
        tmp=x[i]-a*m; //自然烘干可以同时对所有衣服进行
        if(tmp<=0)
            continue;
        s+=(tmp-1)/b+1;  //上取整
        if(s>m)
            return 0;
    }
    return s<=m;
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    int l=1,r=500000,mid,ans;  //右边界合适即可，不要太大
    while(l<=r){
        mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}