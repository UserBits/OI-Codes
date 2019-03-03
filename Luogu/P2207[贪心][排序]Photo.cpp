#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
struct node{
    int l,r;
}a[1005];
bool cmp(node x,node y){
    return x.r<y.r;
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].l,&a[i].r);
        if(a[i].l>a[i].r)
            swap(a[i].l,a[i].r);
    }
    sort(a,a+n,cmp);
    int cnt=1,tmp=-1;
    for(int i=0;i<n;i++){
        if(a[i].l>=tmp){
            cnt++;
            tmp=a[i].r;
        }
    }
    printf("%d\n",cnt);
    //system("pause");
    return 0;
}