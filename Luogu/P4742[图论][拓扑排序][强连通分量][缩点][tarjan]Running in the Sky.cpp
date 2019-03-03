#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

const int N=200001,M=500001;

struct edge{
	int from,node,next;
}edge[M],graph[M];
int head[N],n,m,tot,light[N];

inline void add(int x,int y){
	++tot;
	edge[tot].node=y;
	edge[tot].next=head[x];
	edge[tot].from=x;
	head[x]=tot;
}

int low[N],dfn[N],col[N],sum[N],kite[N],num,color;
bool ins[N];
stack<int> s;

void tarjan(int u){

	dfn[u]=low[u]=++num;
	ins[u]=1;
	s.push(u);

	for(int k=head[u];k;k=edge[k].next){
		int v=edge[k].node;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else{
			if(ins[v])
				low[u]=min(low[u],low[v]);
		}
	}

	if(dfn[u]==low[u]){
		col[u]=++color;
		sum[color]=kite[color]=light[u];
		ins[u]=0;

		while(s.top()!=u){
			col[s.top()]=color;
			sum[color]+=light[s.top()];
			kite[color]=max(kite[color],light[s.top()]);
			ins[s.top()]=0;
			s.pop();
		}

		s.pop();
	}

}

int dis[N],maxlight[N],ind[N];
queue<int> q;

void topsort(int s){

	for(int i=1;i<=color;i++){
		dis[i]=sum[i];
		maxlight[i]=kite[i];
	}
	for(int i=1;i<=color;i++){
		if(!ind[i])
			q.push(i);
	}

	int u,v;
	while(!q.empty()){
		u=q.front();
		q.pop();

		for(int k=head[u];k;k=graph[k].next){

			v=graph[k].node;
			if(dis[u]+sum[v]>dis[v]){
				dis[v]=dis[u]+sum[v];
				maxlight[v]=max(maxlight[u],kite[v]);
			}
			else if(dis[u]+sum[v]==dis[v])
				maxlight[v]=max(maxlight[v],maxlight[u]);

			ind[v]--;
			if(!ind[v])
				q.push(v);

		}

	}

}

int main(){

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&light[i]);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}

	for(int i=1;i<=n;i++){
		if(!dfn[i])
			tarjan(i);
	}

	memset(head,0,sizeof(head)); tot=0;
	for(int i=1;i<=m;i++){
		x=col[edge[i].from];
		y=col[edge[i].node];
		if(x!=y){
			++tot;
			graph[tot].next=head[x];
			graph[tot].node=y;
			head[x]=tot;
			++ind[y];
		}
	}

	topsort(col[1]);
	int ans1=0,ans2=0;
	for(int i=1;i<=color;i++){
		if(dis[i]>ans1 || (dis[i]==ans1 && maxlight[i]>ans2)){
			ans1=dis[i];
			ans2=maxlight[i];
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;

}
