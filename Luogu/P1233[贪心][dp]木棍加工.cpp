#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
struct node{
    int l,w;
}a[5005];
bool v[5005];
bool cmp(node x,node y){
    if(x.l!=y.l)
        return x.l>y.l;
    return x.w>y.w;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].l,&a[i].w);
    sort(a+1,a+1+n,cmp);
    // 先按长度排序，然后用贪心法找宽度的最长不上升子序列
    for(int i=1;i<=n;i++){
        if(!v[i]){
            int tmp=a[i].w;
            for(int j=i+1;j<=n;j++){
                if(a[j].w<=tmp && !v[j]){ //能够一次性处理完的
                    v[j]=1;
                    tmp=a[j].w;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=(!v[i]);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}