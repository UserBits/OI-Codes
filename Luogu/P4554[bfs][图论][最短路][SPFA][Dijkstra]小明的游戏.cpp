#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
const int N=250005,M=1000005;
struct edge{
    int node,next,val;
}Edge[M];
int Head[N],Dis[N],n,tot;
bool v[N];
struct qNode{
    int key,len;
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
inline void gc(char &s){
    s=getchar();
    while(s!='#'&&s!='@')
        s=getchar();
}
void Dijkstra(int s){
    for(int i=1;i<=n;i++){
        v[i]=0;
        Dis[i]=1e9;
    }
    Dis[s]=0;
    priority_queue<qNode> q;
    q.push((qNode){s,0});
    qNode r;
    while(!q.empty()){
        r=q.top();
        q.pop();
        if(!v[r.key]){
            v[r.key]=1;
            for(int k=Head[r.key];k;k=Edge[k].next){
                if(!v[Edge[k].node] && Dis[r.key]+Edge[k].val<Dis[Edge[k].node]){
                    Dis[Edge[k].node]=Dis[r.key]+Edge[k].val;
                    q.push((qNode){Edge[k].node,Dis[Edge[k].node]});
                }
            }
        }
    }
}
char t[505][505];
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
    int ln,lm;
    while(scanf("%d%d",&ln,&lm)!=EOF){
        if(ln==0 && lm==0)
            break;
        memset(Head,0,sizeof(Head));
        for(int i=0;i<ln;i++){
            for(int j=0;j<lm;j++)
                gc(t[i][j]);
        }
        tot=0;
        n=ln*lm;
        int x,y;
        for(int i=0;i<ln;i++){
            for(int j=0;j<lm;j++){
                for(int k=0;k<4;k++){
                    x=i+d[k][0];
                    y=j+d[k][1];
                    if(x>=0 && x<ln && y>=0 && y<lm){
                        if(t[i][j]==t[x][y])
                            Add(i*lm+j+1,x*lm+y+1,0);
                        else
                            Add(i*lm+j+1,x*lm+y+1,1);
                    }
                }
            }
        }
        scanf("%d%d",&x,&y);
        Dijkstra(x*lm+y+1);
        scanf("%d%d",&x,&y);
        printf("%d\n",Dis[x*lm+y+1]);
    }
    return 0;
}