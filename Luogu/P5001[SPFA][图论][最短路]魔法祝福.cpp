//这题卡快读，切勿用fread
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N=1000001;
struct edge{
    int node,next,cost,range;
}Edge[N<<1];
int Head[N],Dis[N],Mne[N],n,m,tot,q[N<<1];
bool Inq[N];

inline void Add(int x,int y,int l,int rg){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].cost=l;
    Edge[tot].range=rg;
    Head[x]=tot;
}

void SPFA(int s){
    for(int i=1;i<=n;i++)
        Dis[i]=Mne[i]=1e9;
    Dis[s]=0; Mne[s]=0;
    Inq[s]=1;
    int r,f=1,t=0;
    q[++t]=s;
    while(f<=t){
        r=q[f++];
        Inq[r]=0;
        for(int k=Head[r];k;k=Edge[k].next){
            if(Mne[r]>=Edge[k].range)
                continue;
            if(Dis[r]+Edge[k].cost<Dis[Edge[k].node] ||
               (Dis[r]+Edge[k].cost==Dis[Edge[k].node] && Mne[r]+1<Mne[Edge[k].node])){
                Dis[Edge[k].node]=Dis[r]+Edge[k].cost;
                Mne[Edge[k].node]=Mne[r]+1;
                if(!Inq[Edge[k].node]){
                    q[++t]=Edge[k].node;
                    Inq[Edge[k].node]=1;
                }
            }
        }
    }
}

int main(){
    int s,t,x,y,l,rg;
	scanf("%d%d%d%d",&n,&m,&s,&t);
    while(m--){
        scanf("%d%d%d%d",&x,&y,&l,&rg);
        Add(x,y,l,rg);
        Add(y,x,l,rg);
    }
    SPFA(s);
    if(Dis[t]==1e9)
        puts("bao 0");
    else
        printf("%d\n",Dis[t]);
    return 0;
}
