#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N=5005,M=200005;
struct edge{
    int node,next,len;
}Edge[M];
int Head[N],Disx[N],Disy[N],tot,n,m;
bool Inq[N];
inline void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].len=l;
    Head[x]=tot;
}
void SPFA(){
    queue<int> q;
    q.push(n);
    Inq[n]=1;
    for(int i=1;i<=n;i++)
        Disx[i]=Disy[i]=1e9;
    Disx[n]=0;
    int r;
    while(!q.empty()){
        r=q.front();
        q.pop();
        Inq[r]=0;
        for(int k=Head[r];k;k=Edge[k].next){
            if(Disx[r]+Edge[k].len<Disx[Edge[k].node]){
                Disx[Edge[k].node]=Disx[r]+Edge[k].len;
                if(!Inq[Edge[k].node]){
                    Inq[Edge[k].node]=1;
                    q.push(Edge[k].node);
                }
            }
            if(Disx[r]+Edge[k].len>Disx[Edge[k].node] && Disx[r]+Edge[k].len<Disy[Edge[k].node]){
                Disy[Edge[k].node]=Disx[r]+Edge[k].len;
                if(!Inq[Edge[k].node]){
                    Inq[Edge[k].node]=1;
                    q.push(Edge[k].node);
                }
            }
            if(Disy[r]+Edge[k].len<Disy[Edge[k].node]){
                Disy[Edge[k].node]=Disy[r]+Edge[k].len;
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
    int x,y,l;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&l);
        Add(x,y,l); Add(y,x,l);
    }
    SPFA();
    printf("%d\n",Disy[1]);
    return 0;
}