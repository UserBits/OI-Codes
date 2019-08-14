#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

char ss[1 << 17], *A = ss, *B = ss;
inline char gc(){
    return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? EOF : *A++;
}
inline void qr(int &s){
	s = 0;
	char c = gc();
	for(; c < '0' || c > '9'; c = gc());
	for(; c >= '0' && c <= '9'; c = gc())
		s = (s << 1) + (s << 3) + c - '0';
}

const int N = 100001, M = 500001;
struct Edge{
	int from, node, next, val;
}edge[M][2];
int head[N], n, m, k, tot, src[N][2];
bool city[N], vis[N];
long long dis[N][2];

inline void add_edge(int x, int y, int l, int p){
	edge[++tot][p] = (Edge){x, y, head[x], l};
	head[x] = tot;
}

struct qNode{
	int key;
	long long len;
	friend bool operator < (qNode x, qNode y){
		return x.len > y.len;
	}
};

priority_queue<qNode> q;

void Dijkstra(int p){
	for(int i = 1; i <= n; ++i){
		if(city[i]){
			dis[i][p] = 0;
			src[i][p] = i;
			q.push((qNode){i, 0});
		}
		else{
			dis[i][p] = 1e18;
			src[i][p] = 0;
		}
		vis[i] = 0;
	}
	qNode x;
	int y;
	while(!q.empty()){
		x = q.top();
		q.pop();
		if(vis[x.key])
			continue;
		vis[x.key] = 1;
		for(int k = head[x.key]; k; k = edge[k][p].next){
			y = edge[k][p].node;
			if(dis[x.key][p] + edge[k][p].val < dis[y][p]){
				dis[y][p] = dis[x.key][p] + edge[k][p].val;
				src[y][p] = src[x.key][p];
				q.push((qNode){y, dis[y][p]});
			}
		}
	}
}

int main(){
	int DC, x, y, l;
	qr(DC);
	while(DC--){
		tot = 0;
		qr(n); qr(m); qr(k);
		for(int i = 1; i <= n; ++i){
			head[i] = 0;
			city[i] = 0;
		}
		for(int i = 1; i <= m; ++i){
			qr(x); qr(y); qr(l);
			if(x ^ y)
				add_edge(x, y, l, 0);
		}
		for(int i = 1; i <= k; ++i){
			qr(x);
			city[x] = 1;
		}
		Dijkstra(0);
		int cnt = tot;
		for(int i = 1; i <= n; ++i)
			head[i] = 0;
		tot = 0;
		for(int i = 1; i <= cnt; ++i)
			add_edge(edge[i][0].node, edge[i][0].from, edge[i][0].val, 1);
		Dijkstra(1);
		long long ans = 2e18;
		for(int i = 1; i <= cnt; ++i){
			x = edge[i][0].from, y = edge[i][0].node;
			if(src[x][0] && src[y][1] && src[x][0] ^ src[y][1])
				ans = min(ans, edge[i][0].val + dis[x][0] + dis[y][1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
