#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N=100005,M=400005;
struct edge{
	int node,next,val;
}Edge[M];
int m,n,tot,Head[N],st,ed1,ed2,Dis[N];
bool v[N];
struct qNode{
	int key,len;
	friend bool operator < (qNode x, qNode y){
		return x.len>y.len;
	}
};
inline void Add(int x,int y,int l){
	tot++;
	Edge[tot].node=y;
	Edge[tot].next=Head[x];
	Edge[tot].val=l;
	Head[x]=tot;
}
void Dijkstra(int s){
	for(int i=1;i<=n;i++){
		Dis[i]=1e9+1;
		v[i]=0;
	}
	priority_queue<qNode> q;
	q.push((qNode){s,0});
	Dis[s]=0; qNode r;
	while(!q.empty()){
		r=q.top(); q.pop();
		if(v[r.key])
			continue;
		v[r.key]=1;
		for(int k=Head[r.key];k;k=Edge[k].next){
			if(Dis[r.key]+Edge[k].val<Dis[Edge[k].node]){
				Dis[Edge[k].node]=Dis[r.key]+Edge[k].val;
				q.push((qNode){Edge[k].node,Dis[Edge[k].node]});
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&m,&n,&st,&ed1,&ed2);
	int x,y,l;
	while(m--){
		scanf("%d%d%d",&x,&y,&l);
		Add(x,y,l); Add(y,x,l);
	}
	Dijkstra(ed1);
	x=Dis[st]+Dis[ed2];
	Dijkstra(ed2);
	y=Dis[st]+Dis[ed1];
	if(x<y)
		printf("%d\n",x);
	else
		printf("%d\n",y);
	return 0;
}
