#include <cstdio>
#include <algorithm>
const int N=100005;
struct Snow{
    int dep,loc;
    friend bool operator < (Snow x, Snow y){
        return x.dep<y.dep;
    }
}h[N];
bool r[N];
int last[N],next[N];
struct Boot{
    int dep,dis,loc;
    friend bool operator < (Boot x, Boot y){
        return x.dep<y.dep;
    }
}a[N];
int main(){
    int n,b,len=0;
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i].dep);
        h[i].loc=i;
        last[i]=i-1;
        next[i]=i+1;
    }
    std::sort(h+1,h+1+n);
    for(int i=1;i<=b;i++){
        scanf("%d%d",&a[i].dep,&a[i].dis);
        a[i].loc=i;
    }
    std::sort(a+1,a+1+b);
    int x=b,y=n;
    while(x>0){//双指针扫描
        while(y>0 && h[y].dep>a[x].dep){//双向链表求解
            last[next[h[y].loc]]=last[h[y].loc];
            next[last[h[y].loc]]=next[h[y].loc];
            len=std::max(len,next[h[y].loc]-last[h[y].loc]);
            y--;
        }
        r[a[x].loc]=(a[x].dis>=len);
        x--;
    }
    for(int i=1;i<=b;i++)
        printf("%d\n",r[i]);
    return 0;
}