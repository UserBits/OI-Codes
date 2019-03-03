#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
const int N=150,M=20005;
struct edge{
    int node,next,val;
}Edge[M];
int Head[N],Dis[N],tot;
bool Inq[N],Cow[N];
void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].val=l;
    Head[x]=tot;
}
void SPFA(){
    for(int i=0;i<N;i++)
        Dis[i]=1e9;
    Dis['Z']=0;
    Inq['Z']=1;
    queue<int> q;
    q.push('Z');
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
int main(){
    int n,l;
    scanf("%d",&n);
    char x,y;
    while(n--){
        cin>>x>>y>>l;
        Add(x,y,l);
        Add(y,x,l);
    }
    SPFA();
    char id='A';
    for(char i='B';i<='Y';i++){
        if(Dis[i]<Dis[id])
            id=i;
    }
    printf("%c %d\n",id,Dis[id]);
    return 0;
}