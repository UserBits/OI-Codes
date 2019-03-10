#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

const int N=10001,M=100001;

struct Edge{
	int node,next,val;
}edge[M];
struct Head{
	int first,val;
}head[N];

int t[N],n,m,s,tot,u,v;
long long dis[N];

inline void add(int x,int y,int l){
	edge[++tot].node=y;
	edge[tot].next=head[x].first;
	edge[tot].val=l;
	head[x].first=tot;
}

bool spfa(int limit){
	for(int i=1;i<=n;i++)
		dis[i]=1e18;
	deque<int> q;
	q.push_back(u);
	dis[u]=0;
	int x,y;
	while(!q.empty()){
		x=q.front();
		q.pop_front();
		if(head[x].val>limit)
			continue;
		for(int k=head[x].first;k;k=edge[k].next){
			y=edge[k].node;
			if(head[y].val>limit)
				continue;
			if(dis[x]+edge[k].val<dis[y]){
				dis[y]=dis[x]+edge[k].val;
				if(!q.empty() && dis[y]<dis[q.front()])
					q.push_front(y);
				else
					q.push_back(y);
			}
		}
	}
	return dis[v]<=s;
}

int main(){
 	scanf("%d%d%d%d%d",&n,&m,&u,&v,&s);
	for(int i=1;i<=n;i++){
  		scanf("%d",&head[i].val);
		t[i]=head[i].val;
	}
	int x,y,len;
	while(m--){
  		scanf("%d%d%d",&x,&y,&len);
		add(x,y,len);
		add(y,x,len);
	}
	sort(t+1,t+1+n);
	int l=1,r=n,mid,ans=-1;
	while(l<=r){
		mid=l+r>>1;
		if(spfa(t[mid])){
			ans=t[mid];
			r=mid-1;
		}
		else
			l=mid+1;
	}
	if(ans>0)
		printf("%d\n",ans);
	else
		puts("-1");
	return 0;
}
