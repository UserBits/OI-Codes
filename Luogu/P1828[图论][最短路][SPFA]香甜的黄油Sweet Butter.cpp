#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
const int N=805,M=3005;
struct edge{
    int node,next,cost;
}Edge[M];
int Head[N],Dis[N],tot,n,m,a[N];
bool Inq[N];
inline void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].cost=l;
    Head[x]=tot;
}
void SPFA(int s){
    queue<int> q;
    q.push(s);
    for(int i=1;i<=n;i++){
        Inq[i]=0;
        Dis[i]=1e9;
    }
    Dis[s]=0;
    Inq[s]=1;
    int r;
    while(!q.empty()){
        r=q.front();
        q.pop();
        Inq[r]=0;
        for(int k=Head[r];k;k=Edge[k].next){
            if(Dis[r]+Edge[k].cost<Dis[Edge[k].node]){
                Dis[Edge[k].node]=Dis[r]+Edge[k].cost;
                if(!Inq[Edge[k].node]){
                    Inq[Edge[k].node]=1;
                    q.push(Edge[k].node);
                }
            }
        }
    }
}
int main(){
    int p;
    scanf("%d%d%d",&p,&n,&m);
    for(int i=1;i<=p;i++)
        scanf("%d",&a[i]);
    int x,y,l,ans=2e9;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&l);
        Add(x,y,l); Add(y,x,l);
    }
    for(int i=1;i<=n;i++){
        SPFA(i);
        int sum=0;
        for(int j=1;j<=p;j++)
            sum+=Dis[a[j]];
        ans=min(ans,sum);
    }
    printf("%d\n",ans);
    return 0;
}