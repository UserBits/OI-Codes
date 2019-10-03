#include <cstdio>
#include <algorithm>

using namespace std;

char ss[1 << 17], * A = ss, * B = ss;
inline char gc() {
	return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? EOF : *A++;
}
template<typename qRead>
inline void qr(qRead& s) {
	char c = gc();
	s = 0;
	bool p = 0;
	for(; c < '0' || c > '9'; c = gc())
		c == '-' ? p = 1 : 0;
	for(; c >= '0' && c <= '9'; c = gc())
		s = (s << 1) + (s << 3) + (c - '0');
	p ? s = -s : 0;
}

const int N = 100005;
struct Edge {
	int node, next;
}edge[N << 1];
int head[N], n, tot, add[N << 2], sum[N << 2];
inline void add_edge(int x, int y) {
	edge[++tot].node = y;
	edge[tot].next = head[x];
	head[x] = tot;
}

int son[N], top[N], dep[N], id[N], fa[N], siz[N], num;
void dfs1(int u, int f, int d) {
	siz[u] = 1;
	fa[u] = f;
	dep[u] = d;
	for(int k = head[u], v; k; k = edge[k].next) {
		v = edge[k].node;
		if(v == f)
			continue;
		dfs1(v, u, d + 1);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]])
			son[u] = v;
	}
}
void dfs2(int u, int rt) {
	id[u] = ++num;
	top[u] = rt;
	if(!son[u])
		return;
	dfs2(son[u], rt);
	for(int k = head[u], v; k; k = edge[k].next) {
		v = edge[k].node;
		if(v == fa[u] || v == son[u])
			continue;
		dfs2(v, v);
	}
}

inline void pushup(int u) {
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
}
inline void pushdown(int u, int ln, int rn) {
	if(add[u]) {
		add[u << 1] += add[u], add[u << 1 | 1] += add[u];
		sum[u << 1] += add[u] * ln;
		sum[u << 1 | 1] += add[u] * rn;
		add[u] = 0;
	}
}

void update(int rt, int L, int R, int v, int now_l, int now_r) {
	if(L <= now_l && now_r <= R) {
		add[rt] += v;
		sum[rt] += v * (now_r - now_l + 1);
		return;
	}
	int mid = now_l + now_r >> 1;
	pushdown(rt, mid - now_l + 1, now_r - mid);
	if(L <= mid)
		update(rt << 1, L, R, v, now_l, mid);
	if(R > mid)
		update(rt << 1 | 1, L, R, v, mid + 1, now_r);
	pushup(rt);
}
int query(int rt, int L, int R, int now_l, int now_r) {
	if(L <= now_l && now_r <= R)
		return sum[rt];
	int mid = now_l + now_r >> 1, ans = 0;
	pushdown(rt, mid - now_l + 1, now_r - mid);
	if(L <= mid)
		ans += query(rt << 1, L, R, now_l, mid);
	if(R > mid)
		ans += query(rt << 1 | 1, L, R, mid + 1, now_r);
	pushup(rt);
	return ans;
}

void range_update(int x, int y, int z) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		update(1, id[top[x]], id[x], z, 1, n);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		swap(x, y);
	update(1, id[x], id[y], z, 1, n);
}
bool range_query(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		if(query(1, id[top[x]], id[x], 1, n))
			return 1;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		swap(x, y);
	if(query(1, id[x], id[y], 1, n))
		return 1;
	else
		return 0;
}

int main() {
	int q, x, y, u, v;
	qr(n); qr(q);
	for(int i = 1; i < n; i++) {
		qr(x); qr(y);
		add_edge(x, y);
		add_edge(y, x);
	}
	dfs1(1, 0, 1);
	dfs2(1, 1);
	while(q--) {
		qr(x); qr(y);
		qr(u); qr(v);
		range_update(x, y, 1);
		if(range_query(u, v))
			puts("Y");
		else
			puts("N");
		range_update(x, y, -1);
	}
	return 0;
}
