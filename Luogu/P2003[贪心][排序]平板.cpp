#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct node
{
    int l,r,h;
}a[1005];
bool cmp(node x,node y)
{
    if(x.l!=y.l)
        return x.l<y.l;
    return x.r<y.r;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].h,&a[i].l,&a[i].r);
    sort(a+1,a+1+n,cmp);
    a[0].h=0;
    a[0].l=0;
    a[0].r=1<<30;
    long long ans=0;
    for(int i=1;i<=n;i++){
        int minl=1<<30,minr=1<<30;
        for(int j=0;j<=n;j++){
            if(i==j)
                continue;
            if(a[j].l<=a[i].l && a[j].r>a[i].l && a[j].h<a[i].h){
                if(a[i].h-a[j].h<minl)
                    minl=a[i].h-a[j].h;
            }
            if(a[j].r>=a[i].r && a[j].l<a[i].r && a[j].h<a[i].h){
                if(a[i].h-a[j].h<minr)
                    minr=a[i].h-a[j].h;
            }
            //printf("(%d %d)\n",minl,minr);
        }
        ans+=minl+minr;
        //printf("%d %d [%lld]\n",minl,minr,ans);
    }
    cout<<ans<<endl;
    return 0;
}
