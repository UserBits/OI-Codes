#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N=10005,M=100005;
typedef long long ll;
struct edge{
    int node,next,cost;
}Edge[M];
ll Dis[N];
int Head[N],tot,n,m,City[N],Blood;
bool Inq[N];
inline void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].cost=l;
    Head[x]=tot;
}
bool SPFA(int x){
    memset(Inq,0,sizeof(Inq));
    for(int i=2;i<=n;i++)
        Dis[i]=1ll<<60;
    queue<int> q;
    q.push(1);
    Inq[1]=1;
    Dis[1]=0;
    int r;
    while(!q.empty()){
        r=q.front();
        q.pop();
        Inq[r]=0;
        for(int k=Head[r];k;k=Edge[k].next){
            if(Dis[r]+Edge[k].cost<Dis[Edge[k].node] && City[Edge[k].node]<=x){
                Dis[Edge[k].node]=Dis[r]+Edge[k].cost;
                if(!Inq[Edge[k].node]){
                    Inq[Edge[k].node]=1;
                    q.push(Edge[k].node);
                }
            }
        }
    }
    if(Dis[n]<=Blood)
        return 1;
    else    
        return 0;
}
int main(){
    scanf("%d%d%d",&n,&m,&Blood);
    for(int i=1;i<=n;i++)
        scanf("%d",&City[i]);
    int x,y,d;
    while(m--){
        scanf("%d%d%d",&x,&y,&d);
        Add(x,y,d);
        Add(y,x,d);
    }
    if(!SPFA(2e9)){
        puts("AFK");
        return 0;
    }
    int l=1,r=2e9,mid,ans;
    while(l<=r){
        mid=l+r>>1;
        if(SPFA(mid)){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}