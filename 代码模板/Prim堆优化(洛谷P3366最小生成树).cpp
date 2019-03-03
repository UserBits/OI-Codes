//PrimÀ„∑®∂—”≈ªØ
#include <cstdio>
#include <algorithm>
#include <cstring>
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

const int N=5001,M=400001;
struct edge{
	int node,next,val;
}Edge[M];
struct qNode{
	int key,len;
	friend bool operator < (qNode x,qNode y){
		return x.len>y.len;
	}
};
int Head[N],n,m,tot,ans,cnt,Dis[N];
bool v[N];
inline void Add(int x,int y,int l){
	tot++;
	Edge[tot].node=y;
	Edge[tot].next=Head[x];
	Edge[tot].val=l;
	Head[x]=tot;
}

void Prim(int st){
	for(int i=1;i<=n;i++)
		Dis[i]=2e9;
	Dis[st]=0;
	priority_queue<qNode> q;
	q.push((qNode){st,0});
	qNode r;
	while(!q.empty() && cnt<n){
		r=q.top(); q.pop();
		if(v[r.key])
			continue;
		v[r.key]=1; cnt++; ans+=r.len;
		for(int k=Head[r.key];k;k=Edge[k].next){
			if(Edge[k].val<Dis[Edge[k].node]){
				Dis[Edge[k].node]=Edge[k].val;
				q.push((qNode){Edge[k].node,Dis[Edge[k].node]});
			}
		}
	}
}

int main(){
	qr(n); qr(m);
	int x,y,l;
	while(m--){
		qr(x); qr(y); qr(l);
		Add(x,y,l); Add(y,x,l);
	}
	Prim(1);
	if(cnt==n)
		printf("%d\n",ans);
	else
		puts("orz");
	return 0;
}
