#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

const int N=2005,M=200005;
struct edge{
    int node,next;
    double cost;
}Edge[M];
int n,m,tot,Head[N];
double Dis[N];
bool Inq[N];

inline void Add(int x,int y,double l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].cost=l;
    Head[x]=tot;
}

void SPFA(int s){
    queue<int> q;
    Dis[s]=1;
    q.push(s);
    Inq[s]=1;
    int r,k;
    while(!q.empty()){
        r=q.front(); q.pop();
        Inq[r]=0;
        for(k=Head[r];k;k=Edge[k].next){
            if(Dis[r]*Edge[k].cost>Dis[Edge[k].node]){
                Dis[Edge[k].node]=Dis[r]*Edge[k].cost;
                if(!Inq[Edge[k].node]){
                    Inq[Edge[k].node]=1;
                    q.push(Edge[k].node);
                }
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    double l;
    while(m--){
        scanf("%d%d%lf",&x,&y,&l);
        l/=100.0;
        l=1-l;
        Add(x,y,l);
        Add(y,x,l);
    }
    scanf("%d%d",&x,&y);
    SPFA(x);
    printf("%.8lf\n",100.0/Dis[y]);
    return 0;
}