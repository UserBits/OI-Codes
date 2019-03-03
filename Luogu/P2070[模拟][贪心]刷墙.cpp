#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct node{
    int l,r;
}a[100005];
bool cmp(node x,node y){
    if(x.l!=y.l)
        return x.l<y.l;
    return x.r<y.r;
}
int main(){
    int n,tmp,pos=0;
    scanf("%d",&n);
    char c;
    for(int i=1;i<=n;i++){
        cin>>tmp>>c;
        if(c=='L'){
            a[i].l=pos-tmp;
            a[i].r=pos;
            pos-=tmp;
        }
        else if(c=='R'){
            a[i].l=pos;
            a[i].r=pos+tmp;
            pos+=tmp;
        }
    }
    sort(a+1,a+1+n,cmp);
    int last=-1<<30,ans=0;
    tmp=a[1].r;
    for(int i=2;i<=n;i++){
        if(a[i].l<=tmp){
            if(min(a[i].r,tmp)-max(a[i].l,last)>0){
                ans+=min(a[i].r,tmp)-max(a[i].l,last);
                last=min(a[i].r,tmp);
            }
        }
        tmp=max(tmp,a[i].r);
    }
    printf("%d\n",ans);
    return 0;
}
