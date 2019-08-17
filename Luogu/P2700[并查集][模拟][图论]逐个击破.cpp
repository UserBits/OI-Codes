#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
struct node{
	int u,v,w;
	friend bool operator < (node x,node y){
		return x.w<y.w;
	}
};
priority_queue<node> q;
int b[100005],f[100005],vis[100005];
int Find(int x){
	if(f[x]==x)
		return x;
	return f[x]=Find(f[x]);
}
void Merge(int x,int y){
	x=Find(x);
	y=Find(y);
	if(x==y)
		return;
	f[x]=y;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i]);
		b[i]++;
		vis[b[i]]=1;
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	long long ans=0,sum=0;
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		u++; v++;
		q.push((node){u,v,w});
		sum+=w;
	}
	while(!q.empty()){
		node e=q.top();
		int x=Find(e.u);
		int y=Find(e.v);
		if(!(vis[x] && vis[y])){
			f[y]=x;
			vis[x]=vis[x]||vis[y];
			ans+=e.w;
		}
		q.pop();
	}
	printf("%lld\n",sum-ans);
	return 0;
}
