#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int N=100005,M=300005,mod=1e9+7;
struct Edge{
	int node,next;
}edge[M];
struct Head{
	int first,val;
}head[N];
int n,m,tot,dfn[N],low[N],col[N],cost[N],color,num,ways[N];
inline void add(int x,int y){
	edge[++tot].node=y;
	edge[tot].next=head[x].first;
	head[x].first=tot;
}

bool ins[N]; stack<int> s;
void tarjan(int u){
	low[u]=dfn[u]=++num;
	s.push(u); ins[u]=1;
	for(int k=head[u].first;k;k=edge[k].next){
		int v=edge[k].node;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else{
			if(ins[v])
				low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		ins[u]=0; col[u]=++color;
		cost[color]=head[u].val;
		while(s.top()!=u){
			ins[s.top()]=0;
			col[s.top()]=color;
			cost[color]=min(cost[color],head[s.top()].val);
			s.pop();
		}
		s.pop();
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&head[i].val);
	scanf("%d",&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])
			tarjan(i);
	}
	for(int i=1;i<=n;i++){
		if(head[i].val==cost[col[i]])
			ways[col[i]]++;
	}
	long long ans=0,sum=1;
	for(int i=1;i<=color;i++){
		ans+=cost[i];
		sum=sum*ways[i]%mod;
	}
	printf("%lld %lld\n",ans,sum);
	return 0;
}
