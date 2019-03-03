#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
const int N=50005,M=200005;
struct edge{
    int node,next,val;
}Edge[M];
int n,m,b,tot,Head[N],Dis[N];
bool Inq[N];
void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].val=l;
    Head[x]=tot;
}
void Spfa(int s){
    for(int i=1;i<=n;i++)
        Dis[i]=1e9;
    Inq[s]=1;
    Dis[s]=0;
    queue<int> q;
    q.push(s);
    int r;
    while(!q.empty()){
        r=q.front();
        q.pop();
        Inq[r]=0;
        for(int k=Head[r];k;k=Edge[k].next){
            if(Dis[r]+Edge[k].val<Dis[Edge[k].node]){
                Dis[Edge[k].node]=Dis[r]+Edge[k].val;
                if(!Inq[Edge[k].node]){
                    Inq[Edge[k].node]=1;
                    q.push(Edge[k].node);
                }
            }
        }
    }
}
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    scanf("%d%d%d",&n,&m,&b);
    int x,y,l;
    for(int i=1;i<=m;i++){
        qr(x);  qr(y);  qr(l);
        Add(x,y,l);
        Add(y,x,l); //无向图
    }
    Spfa(1);
    while(b--){
        qr(x);  qr(y);
        printf("%d\n",Dis[x]+Dis[y]);
    }
    return 0;
}