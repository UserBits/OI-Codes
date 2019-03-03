#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N=10005,M=100005,K=25;
struct edge{
	int node,next,val;
}Edge[M]; //分层图求最短路
struct qNode{
	int key,dep,len;
	//点的标号、层次、距离
	friend bool operator < (qNode x, qNode y){
		return x.len>y.len;
	}
};
int Head[N],Dis[N][K],n,m,tot,Cnt;
bool v[N][K];
inline void Add(int x,int y,int l){
	tot++;
	Edge[tot].node=y;
	Edge[tot].next=Head[x];
	Edge[tot].val=l;
	Head[x]=tot;
}
inline void qr(int &s){
	s=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		s=(s<<1)+(s<<3)+c-'0';
}
int main(){
	scanf("%d%d%d",&n,&m,&Cnt);
	int x,y,l;
	for(int i=1;i<=m;i++){
		qr(x);  qr(y);  qr(l);
		Add(x,y,l);
		Add(y,x,l);
	}
	//printf("%d %d %d %d\n",n,m,Cnt,tot);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=Cnt;j++)
			Dis[i][j]=1e9;
	}
	Dis[1][0]=0;
	priority_queue<qNode> q;
	q.push((qNode){1,0,0});
	qNode r;
	while(!q.empty()){
		r=q.top();
		q.pop();
		if(v[r.key][r.dep])
			continue;
		v[r.key][r.dep]=1;
		for(int k=Head[r.key];k;k=Edge[k].next){
			//分类处理：是在同一层还是分不同层
			if(r.dep<Cnt && Dis[Edge[k].node][r.dep+1]>r.len){
				Dis[Edge[k].node][r.dep+1]=r.len;
				q.push((qNode){Edge[k].node,r.dep+1,Dis[Edge[k].node][r.dep+1]});
			}
			if(r.len+Edge[k].val<Dis[Edge[k].node][r.dep]){//标准的Dijkstra
				Dis[Edge[k].node][r.dep]=r.len+Edge[k].val;
				q.push((qNode){Edge[k].node,r.dep,Dis[Edge[k].node][r.dep]});
			}
		}
	}
	printf("%d\n",Dis[n][Cnt]);
	return 0;
}
