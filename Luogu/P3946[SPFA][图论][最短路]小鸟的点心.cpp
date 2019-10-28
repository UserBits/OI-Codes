#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename qRead>
inline void qr(qRead &s){
    char c=gc();
    s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
}

//预处理出到达每个点的时间上线，spfa时加一个判断
//终点无需此判断

const int N=100005,M=1000005;
struct Edge{
	int node,next,val;
}edge[M];
struct Head{
	int first,lim;
}head[N];
int n,m,tot,s,t,limit,add,dis[N];
bool inq[N];
queue<int> q;
inline void add_edge(int x,int y,int l){
	edge[++tot].node=y;
	edge[tot].next=head[x].first;
	edge[tot].val=l;
	head[x].first=tot;
}

void spfa(){
	for(int i=1;i<=n;i++)
		dis[i]=1e9;
	dis[s]=0; inq[s]=1;
	q.push(s);
	int u,v,k,l;
	while(!q.empty()){
		u=q.front();
		q.pop();
		inq[u]=0;
		for(k=head[u].first;k;k=edge[k].next){
			v=edge[k].node;
			l=dis[u]+edge[k].val;
			if(v==t){
				if(l<dis[v]){
					dis[v]=l;
					if(!inq[v]){
						inq[v]=1;
						q.push(v);
					}
				}
			}
			else{
				if(l<dis[v]&&l<head[v].lim){
					dis[v]=l;
					if(!inq[v]){
						inq[v]=1;
						q.push(v);
					}
				}
			}
		}
	}
}

int main(){
	qr(n); qr(m); qr(s); qr(t); qr(limit); qr(add);
	int x,y,w;
	for(int i=1;i<=n;i++){
		qr(x); qr(y);
		if(!add){
			head[i].lim=1e9+1;
			continue;
		}
		head[i].lim=(int)((y*1.0-x)/(add*1.0));
	}
	for(int i=1;i<=m;i++){
		qr(x); qr(y); qr(w);
		add_edge(x,y,w);
		add_edge(y,x,w);
	}
	spfa();
	if(dis[t]<1e9 && dis[t]<=limit)
		printf("%d\n",dis[t]);
	else
		puts("wtnap wa kotori no oyatsu desu!");
	return 0;
}
