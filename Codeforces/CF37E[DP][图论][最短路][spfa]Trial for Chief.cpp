#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
const int N=2501,M=10001;
struct edge{
    int node,next,cost;
}Edge[M];
int n,ln,lm,tot,Head[N],Dis[N],Black[N];
bool Inq[N];
void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].cost=l;
    Head[x]=tot;
}
int GetNum(int x,int y){
    return x*lm+y+1;
}
void SPFA(int s){
    for(int i=1;i<=n;i++){
        Dis[i]=1e9;
        Inq[i]=0;
    }
    queue<int> q;
    q.push(s);
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
                    q.push(Edge[k].node);
                    Inq[Edge[k].node]=1;
                }
            }
        }
    }
}
char mp[51][51];
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
    bool all_white=1;
    int cnt=0,tx,ty;
    scanf("%d%d",&ln,&lm);
    n=ln*lm;
    for(int i=0;i<ln;i++){
        for(int j=0;j<lm;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='B'){
                all_white=0;
                Black[++cnt]=GetNum(i,j);
            }
        }
    }
    if(all_white){
        puts("0");
        return 0;
    }
    for(int i=0;i<ln;i++){
        for(int j=0;j<lm;j++){
            for(int k=0;k<4;k++){
                tx=i+d[k][0];
                ty=j+d[k][1];
                if(tx>=0 && ty>=0 && tx<ln && ty<lm)
                    Add(GetNum(i,j),GetNum(tx,ty),mp[i][j]!=mp[tx][ty]);
            }
        }
    }
    int ans=2e9,tmp;
    for(int i=0;i<ln;i++){
        for(int j=0;j<lm;j++){
            tmp=0;
            SPFA(GetNum(i,j));
            for(int k=1;k<=cnt;k++)
                tmp=max(tmp,Dis[Black[k]]);
            ans=min(ans,tmp);
        }
    }
    printf("%d\n",ans+1);
    return 0;
}