#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N=5005;
int last[N],dp[N];
struct Node{
    int x,y,id;
}a[N];
bool cmp(Node p,Node q){
    if(p.x==q.x)
        return p.y<q.y;
    return p.x<q.x;
}
void Print(int r){
    if(r==-1)
        return;
    Print(last[r]);
    printf("%d ",a[r].id);
}
int main(){
    int DC,n=0,w,h,p,q;
    scanf("%d%d%d",&DC,&w,&h);
    for(int i=1;i<=DC;i++){
        scanf("%d%d",&p,&q);
        if(p>w && q>h){
            n++;
            a[n].x=p;
            a[n].y=q;
            a[n].id=i;
        }
    }
    if(!n){
        puts("0");
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        dp[i]=1;
        last[i]=-1;
    }
    int ans=1,tr=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j].x<a[i].x && a[j].y<a[i].y && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                last[i]=j;
            }
        }
        if(dp[i]>ans){
            ans=dp[i];
            tr=i;
        }
    }
    printf("%d\n",ans);
    Print(tr);
    return 0;
}