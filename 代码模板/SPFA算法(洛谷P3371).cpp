#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
const int N=10005,M=500005;//节点数、边数
struct edge{
    int node,next,val;
    //当前节点、下一个点、当前边权值
}Edge[M];
int Head[N],Dis[N],Cnt[N],n,tot;//Cnt记录访问次数
bool Inq[N];//是否在队列中

inline void Add(int x,int y,int l){//加边
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].val=l;
    Head[x]=tot;
}

bool SPFA(int Src){//源点
//返回bool:是否存在负权环
    queue<int> q;
    q.push(Src);
    Cnt[Src]=1;
    for(int i=1;i<=n;i++)
        Dis[i]=1e9;
    Dis[Src]=0;
    Inq[Src]=1;
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
                    Cnt[Edge[k].node]++;
                    if(Cnt[Edge[k].node]>n)
                        return 0;
                    q.push(Edge[k].node);
                }
            }
        }
    }
    return 1;
}

inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}

int main(){
    //n一定要开全局变量
    int m,s,x,y,l;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        qr(x);
        qr(y);
        qr(l);
        Add(x,y,l);
    }
    if(!SPFA(s)){
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(Dis[i]>=1e9)
            printf("2147483647 ");
        else
            printf("%d ",Dis[i]);
    }
    return 0;
}