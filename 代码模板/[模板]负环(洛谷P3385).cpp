#include <cstdio>
#include <queue>
#include <cstring>

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

const int N = 2001, M = 6001;
struct Edge{
	int node, next, val;
}edge[M];
int head[N], n, m, tot, dis[N], cnt[N];
inline void add(int x, int y, int l){
	edge[++tot].node = y;
	edge[tot].next = head[x];
	edge[tot].val = l;
	head[x] = tot;
}
bool inq[N];

bool spfa(){
	for(int i = 1; i <= n; i++){
		dis[i] = 1e9;
		cnt[i] = 0;
		inq[i] = 0;
	}
	queue<int> q;
	q.push(1);
	inq[1] = 1;
	dis[1] = 0;
	int u, v;
	while(!q.empty()){
		u = q.front();
		q.pop();
		++cnt[u];
		inq[u] = 0;
		if(cnt[u] >= n)
			return 1;
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
	return 0;
}

int main(){
	int t, x, y, l;
	qr(t);
	while(t--){
		memset(head, 0, sizeof(head));
		tot = 0;
		qr(n); qr(m);
		while(m--){
			qr(x); qr(y); qr(l);
			add(x, y, l);
			if(l>=0)
				add(y, x, l);
		}
		if(spfa())
			puts("YE5");
		else
			puts("N0");
	}
	return 0;
}
