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
template<typename qWrite>
inline void qw(qWrite s) {
	if(s < 0) {
		putchar('-');
		s = -s;
	}
	if(s > 9)
		qw(s / 10);
	putchar(s % 10 + '0');
}

const int N = 100005;
typedef long long ll;
struct Edge {
	int node, next;
}edge[N << 1];
struct Head {
	int val, first;
}head[N];
int n, tot, a[N];
ll add[N << 2], sum[N << 2];
inline void add_edge(int x, int y) {
	edge[++tot].node = y;
	edge[tot].next = head[x].first;
	head[x].first = tot;
}

int son[N], top[N], fa[N], siz[N], dep[N], id[N], num;
void dfs1(int u, int f, int d) {
	siz[u] = 1;
	fa[u] = f;
	dep[u] = d;
	for(int k = head[u].first, v; k; k = edge[k].next) {
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
	a[num] = head[u].val;
	if(!son[u])
		return;
	dfs2(son[u], rt);
	for(int k = head[u].first, v; k; k = edge[k].next) {
		v = edge[k].node;
		if(v == fa[u] || v == son[u])
			continue;
		dfs2(v, v);
	}
}

inline void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
inline void pushdown(int rt, int ln, int rn) {
	if(add[rt]) {
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += add[rt] * ln;
		sum[rt << 1 | 1] += add[rt] * rn;
		add[rt] = 0;
	}
}

void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int L, int R, ll v, int now_l, int now_r) {
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

ll query(int rt, int L, int R, int now_l, int now_r) {
	if(L <= now_l && now_r <= R)
		return sum[rt];
	int mid = now_l + now_r >> 1;
	ll ans = 0;
	pushdown(rt, mid - now_l + 1, now_r - mid);
	if(L <= mid)
		ans += query(rt << 1, L, R, now_l, mid);
	if(R > mid)
		ans += query(rt << 1 | 1, L, R, mid + 1, now_r);
	return ans;
}

ll range_query(int x, int y) {
	ll ans = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		ans += query(1, id[top[x]], id[x], 1, n);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		swap(x, y);
	ans += query(1, id[x], id[y], 1, n);
	return ans;
}

void subtree_update(int x, ll y) {
	update(1, id[x], id[x] + siz[x] - 1, y, 1, n);
}
void point_update(int x, ll y) {
	update(1, id[x], id[x], y, 1, n);
}

int main() {
	int dc, op, x, y;
	ll v;
	qr(n); qr(dc);
	for(int i = 1; i <= n; i++)
		qr(head[i].val);
	for(int i = 1; i < n; i++) {
		qr(x); qr(y);
		add_edge(x, y);
		add_edge(y, x);
	}
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	while(dc--) {
		qr(op); qr(x);
		if(op == 1) {
			qr(v);
			point_update(x, v);
		}
		if(op == 2) {
			qr(v);
			subtree_update(x, v);
		}
		if(op == 3) {
			qw(range_query(1, x));
			putchar('\n');
		}
	}
	return 0;
}
