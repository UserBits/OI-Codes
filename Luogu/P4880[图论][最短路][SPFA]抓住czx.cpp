#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
const int N=100005,M=1000005;
struct edge{
    int node,next,val;
}Edge[M];
int Head[N],Dis[N],n,m,tot;
bool Inq[N];
struct Change{
    int x,t;
    friend bool operator < (Change p, Change q){
        return p.t<q.t;
    }
}ch[N];
inline void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].val=l;
    Head[x]=tot;
}
void SPFA(int s){
    for(int i=1;i<=n;i++)
        Dis[i]=1e9;
    Inq[s]=1;
    queue<int> q;
    q.push(s);
    Dis[s]=0;
    int r;
    while(!q.empty()){
        r=q.front();
        q.pop();
        Inq[r]=0;
        for(int k=Head[r];k;k=Edge[k].next){
            if(Dis[r]+Edge[k].val<Dis[Edge[k].node]){
                Dis[Edge[k].node]=Dis[r]+Edge[k].val;
                if(!Inq[Edge[k].node]){
                    q.push(Edge[k].node);
                    Inq[Edge[k].node]=1;
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
    int st,ed,DC,u,v,l;
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for(int i=1;i<=m;i++){
        qr(u);  qr(v);  qr(l);
        Add(u,v,l);
        Add(v,u,l);
    }
    SPFA(st);
    qr(DC);
    for(int i=1;i<=DC;i++){
        qr(ch[i].t);    qr(ch[i].x);
    }
    sort(ch+1,ch+1+DC);
    ch[0].x=ed;
    for(int i=0;i<DC;i++){
        if(Dis[ch[i].x]<ch[i+1].t){
            printf("%d\n",max(Dis[ch[i].x],ch[i].t));
            return 0;
        }
    }
    printf("%d\n",max(Dis[ch[DC].x],ch[DC].t));
    return 0;
}