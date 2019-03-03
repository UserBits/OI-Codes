#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node{
    int l,r;
}a[10005];
int f[10005];
bool cmp(node x,node y){
    return x.l>y.l;
}
int main(){
    int n,total;
    scanf("%d%d",&total,&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+1+n,cmp);
    for(int i=total,j=1;i>0;i--){
        if(a[j].l!=i)
            f[i]=f[i+1]+1;
        else{
            while(a[j].l==i){
                f[i]=max(f[i],f[i+a[j].r]);
                j++;
            }
        }
    }
    printf("%d\n",f[1]);
    return 0;
}