#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int d,p,c,f,s,cnt[225],Head[225],tot,dis[225],Inq[225];
struct Graph{
    int node,next,cost;
}Edge[1000];
void Add(int x,int y,int val){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].cost=val;
    Head[x]=tot;
}
int main(){
    scanf("%d%d%d%d%d",&d,&p,&c,&f,&s);
    int x,y,t;
    for(int i=1;i<=p;i++){
        scanf("%d%d",&x,&y);
        Add(x,y,0);
    }
    for(int i=1;i<=f;i++){
        scanf("%d%d%d",&x,&y,&t);
        Add(x,y,t);
    }
    cnt[s]=1;
    memset(dis,127,sizeof(dis));
    dis[s]=-d;
    Inq[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int r=q.front();
        q.pop();
        Inq[r]=0;
        for(int k=Head[r];k;k=Edge[k].next){
            if(dis[r]+Edge[k].cost-d<dis[Edge[k].node]){
                dis[Edge[k].node]=dis[r]+Edge[k].cost-d;
                if(!Inq[Edge[k].node]){
                    cnt[Edge[k].node]++;
                    if(cnt[Edge[k].node]>c){
                        puts("-1");
                        return 0;
                    }
                    q.push(Edge[k].node);
                    Inq[Edge[k].node]=1;
                }
            }
        }
    }
    int mn=2e9;
    for(int i=1;i<=c;i++)
        mn=min(mn,dis[i]);
    printf("%d\n",-mn);
    return 0;
}
