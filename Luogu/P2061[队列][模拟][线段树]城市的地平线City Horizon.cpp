#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;
const int N=40005;
struct Seg{
    int l,r;
    long long h;
    friend bool operator < (Seg x, Seg y){
        return x.h<y.h;
    }
}a[N];
priority_queue<Seg> q;
int pt[N<<1];
bool cmp1(Seg x,Seg y){
    return x.l<y.l;
}
bool cmp2(int x,int y){
    return x<y;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].h);
        pt[i]=a[i].l; pt[i+n]=a[i].r;
    }
    sort(a+1,a+1+n,cmp1);
    sort(pt+1,pt+1+2*n,cmp2);
    long long sum=0;
    int cnt=0;
    for(int i=1;i<(n<<1);i++){
        while(!q.empty() && q.top().r<=pt[i])
            q.pop();
        while(a[cnt+1].l>=pt[i] && a[cnt+1].l<pt[i+1])
            q.push(a[++cnt]);
        if(!q.empty())
            sum+=(pt[i+1]-pt[i])*q.top().h;
    }
    cout<<sum<<endl;
    return 0;
}