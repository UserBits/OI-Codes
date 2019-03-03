#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
const int N=100005,M=200005;
struct edge{
    int node,next,val;
}Edge[M];
int Head[N],Dis[N],n,tot;
bool v[N];
struct qNode{//优先队列存储节点
    int key,len;
    //key:节点编号
    //len:从源点到key的最短路
    friend bool operator < (qNode x, qNode y){
        return x.len>y.len;
    }
};

void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].val=l;
    Head[x]=tot;
}

void Dijkstra(int Src){ //Src:源点
//Dijkstra堆优化算法
    for(int i=1;i<=n;i++)
        Dis[i]=1e9+1;
    Dis[Src]=0;
    priority_queue<qNode> q;
    q.push((qNode){Src,0});
    qNode r;
    while(!q.empty()){
        r=q.top();
        q.pop();
        if(v[r.key])
            continue;
        v[r.key]=1;//只能在此处标记已访问
        for(int k=Head[r.key];k;k=Edge[k].next){
            if(!v[Edge[k].node] && Dis[r.key]+Edge[k].val<Dis[Edge[k].node]){
                Dis[Edge[k].node]=Dis[r.key]+Edge[k].val;
                q.push((qNode){Edge[k].node,Dis[Edge[k].node]});
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
    int m,s,x,y,l;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        qr(x);  qr(y);  qr(l);
        Add(x,y,l);
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++)
        printf("%d ",Dis[i]);
    //system("pause");
    return 0;
}