#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

char ss[1 << 17], * A = ss, * B = ss;
inline char gc() {
	return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? EOF : *A++;
}
template<typename qRead>
inline void qr(qRead& s) {
	char c = gc();
	s = 0;
	qRead f = 1;
	for(; c < '0' || c > '9'; c = gc()) {
		if(c == '-')
			f = -1;
	}
	for(; c >= '0' && c <= '9'; c = gc())
		s = (s << 1) + (s << 3) + (c - '0');
	s *= f;
}
template<typename qWrite>
inline void qw(qWrite s) {
	if(s < 0) {
		s = -s;
		putchar('-');
	}
	if(s > 9)
		qw(s / 10);
	putchar(s % 10 + '0');
}

const int N = 1005, M = 3005;

struct Edge {
	int node, next;
	double val;
}edge[M];
struct Flag {
	int op, x, y, k;
}flag[N];
int head[N], score[N], vis[N], n, s, tot;
bool inq[N];
double dis[N];
queue<int> q;

inline void add_edge(int x, int y, double l) {
	edge[++tot].node = y;
	edge[tot].next = head[x];
	edge[tot].val = l;
	head[x] = tot;
}

bool check(double t) {
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
	tot = 0;
	while(!q.empty())
		q.pop();
	for(int i = 0; i <= n; i++) {
		dis[i] = 1;
		inq[i] = 1;
		q.push(i);
	}
	for(int i = 1; i <= n; i++) {
		if(score[i]) {
			add_edge(0, i, 1.0 * score[i]);
			add_edge(i, 0, 1.0 / score[i]);
		}
	}
	for(int i = 1; i <= s; i++) {
		if(flag[i].op == 1) {
			add_edge(flag[i].y, flag[i].x, 1.0 * (flag[i].k - t));
		}
		else {
			add_edge(flag[i].y, flag[i].x, 1.0 / (flag[i].k + t));
		}
	}
	int u, v;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		inq[u] = 0;
		++vis[u];
		if(vis[u] >= n) {
			return 1;
		}
		for(int k = head[u]; k; k = edge[k].next) {
			v = edge[k].node;
			if(dis[u] * edge[k].val > dis[v]) {
				dis[v] = dis[u] * edge[k].val;
				if(!inq[v]) {
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return 0;
}

int main() {
	int m, x, y;
	qr(n); qr(s); qr(m);
	double l = 0, r = 1e18, ans = -1, mid;
	for(int i = 1; i <= s; i++) {
		qr(flag[i].op); qr(flag[i].x); qr(flag[i].y); qr(flag[i].k);
		if(flag[i].op == 1 && flag[i].k * 1.0 < r) {
			r = flag[i].k * 1.0;
		}
	}
	for(int i = 1; i <= m; i++) {
		qr(x); qr(y);
		score[x] = y;
	}
	while(r - l > 1e-6) {
		mid = (l + r) / 2;
		if(check(mid)) {
			l = ans = mid;
		}
		else {
			r = mid;
		}
	}
	if(ans == -1) {
		puts("-1");
	}
	else {
		printf("%.6lf\n", ans);
	}
	return 0;
}
