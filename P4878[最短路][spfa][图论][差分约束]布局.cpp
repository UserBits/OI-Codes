#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

char ss[1 << 17], *A = ss, *B = ss;
inline char gc(){
    return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? EOF : *A++;
}
template<typename tp>
inline void qr(tp &s){
	s = 0;
	char c = gc();
	tp f = 1;
	for(; c < '0' || c > '9'; c = gc()){
		if(c == '-')
			f = -1;
	}
	for(; c >= '0' && c <= '9'; c = gc())
		s = (s << 1) + (s << 3) + c - '0';
	s *= f;
}

const int N = 1005, M = 21005;

struct Edge{
	int node, next, val;
}edge[M];
int head[N], n, ml, md, tot, dis[N], vis[N];
bool inq[N];
queue<int> q;

inline void add_edge(int x, int y, int l){
	edge[++tot].node = y;
	edge[tot].next = head[x];
	edge[tot].val = l;
	head[x] = tot;
}

void spfa(int s){
	for(int i = 1; i <= n; i++){
		inq[i] = 0;
		dis[i] = 1e9;
		vis[i] = 0;
	}
	q.push(s);
	inq[s] = 1;
	dis[s] = 0;
	register int u, v;
	while(!q.empty()){
		u = q.front();
		q.pop();
		inq[u] = 0;
		vis[u]++;
		if(vis[u] >= n){
			puts("-1");
			exit(0);
		}
		for(int k = head[u]; k; k = edge[k].next){
			v = edge[k].node;
			if(dis[u] + edge[k].val < dis[v]){
				dis[v] = dis[u] + edge[k].val;
				if(!inq[v]){
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
}

int main(){
	qr(n);
	qr(ml);
	qr(md);
	for(int i = 1; i <= n; i++)
		add_edge(0, i, 0);
	int x, y, l;
	for(int i = 1; i <= ml; i++){
		qr(x);
		qr(y);
		qr(l);
		add_edge(x, y, l);
	}
	for(int i = 1; i <= md; i++){
		qr(x);
		qr(y);
		qr(l);
		add_edge(y, x, -l);
	}
	spfa(0);
	spfa(1);
	if(dis[n]<1e9)
		printf("%d\n", dis[n]);
	else
		puts("-2");
	return 0;
}

