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
		s = -s;
		putchar('-');
	}
	if(s > 9)
		qw(s / 10);
	putchar(s % 10 + '0');
}
inline void readc(char& c) {
	c = gc();
	while(c < 'A' || c > 'Z')
		c = gc();
}

const int N = 20005;
struct Edge {
	int node, next, val;
}edge[N << 1];
int head[N], a[N], add[N << 2], sum[N << 2], mx[N << 2], mn[N << 2], n, tot, tmp[N];
inline void add_edge(int x, int y, int l) {
	edge[++tot].node = y;
	edge[tot].next = head[x];
	edge[tot].val = l;
	head[x] = tot;
}

int son[N], top[N], siz[N], id[N], dep[N], fa[N], num;
void dfs1(int u, int f, int d) {
	fa[u] = f;
	dep[u] = d;
	siz[u] = 1;
	for(int k = head[u], v; k; k = edge[k].next) {
		v = edge[k].node;
		if(v == f)
			continue;
		tmp[v] = edge[k].val;
		dfs1(v, u, d + 1);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]])
			son[u] = v;
	}
}
void dfs2(int u, int rt) {
	top[u] = rt;
	id[u] = ++num;
	a[num] = tmp[u];
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

inline void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}
inline void pushdown(int rt) {
	if(add[rt]) {
		sum[rt << 1] = -sum[rt << 1];
		sum[rt << 1 | 1] = -sum[rt << 1 | 1];
		add[rt << 1] ^= 1;
		add[rt << 1 | 1] ^= 1;
		int x = mx[rt << 1], y = mn[rt << 1];
		mx[rt << 1] = -y;
		mn[rt << 1] = -x;
		x = mx[rt << 1 | 1], y = mn[rt << 1 | 1];
		mx[rt << 1 | 1] = -y;
		mn[rt << 1 | 1] = -x;
		add[rt] = 0;
	}
}

void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = mx[rt] = mn[rt] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int L, int R, int now_l, int now_r) {
	if(L <= now_l && now_r <= R) {
		int t = mx[rt];
		mx[rt] = -mn[rt];
		mn[rt] = -t;
		sum[rt] = -sum[rt];
		add[rt] ^= 1;
		return;
	}
	int mid = now_l + now_r >> 1;
	pushdown(rt);
	if(L <= mid)
		update(rt << 1, L, R, now_l, mid);
	if(R > mid)
		update(rt << 1 | 1, L, R, mid + 1, now_r);
	pushup(rt);
}

void change(int rt, int L, int l, int r, int v) {
	if(l == r) {
		sum[rt] = mx[rt] = mn[rt] = v;
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt);
	if(L <= mid)
		change(rt << 1, L, l, mid, v);
	else
		change(rt << 1 | 1, L, mid + 1, r, v);
	pushup(rt);
}

int query_sum(int rt, int L, int R, int now_l, int now_r) {
	if(L <= now_l && now_r <= R)
		return sum[rt];
	int mid = now_l + now_r >> 1, ans = 0;
	pushdown(rt);
	if(L <= mid)
		ans += query_sum(rt << 1, L, R, now_l, mid);
	if(R > mid)
		ans += query_sum(rt << 1 | 1, L, R, mid + 1, now_r);
	return ans;
}

int query_mx(int rt, int L, int R, int now_l, int now_r) {
	if(L <= now_l && now_r <= R)
		return mx[rt];
	int mid = now_l + now_r >> 1, ans = -2e9;
	pushdown(rt);
	if(L <= mid)
		ans = max(ans, query_mx(rt << 1, L, R, now_l, mid));
	if(R > mid)
		ans = max(ans, query_mx(rt << 1 | 1, L, R, mid + 1, now_r));
	return ans;
}

int query_mn(int rt, int L, int R, int now_l, int now_r) {
	if(L <= now_l && now_r <= R)
		return mn[rt];
	int mid = now_l + now_r >> 1, ans = 2e9;
	pushdown(rt);
	if(L <= mid)
		ans = min(ans, query_mn(rt << 1, L, R, now_l, mid));
	if(R > mid)
		ans = min(ans, query_mn(rt << 1 | 1, L, R, mid + 1, now_r));
	return ans;
}

void range_update(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		update(1, id[top[x]], id[x], 1, n);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		swap(x, y);
	update(1, id[x] + 1, id[y], 1, n);
}

int range_sum(int x, int y) {
	int ans = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		ans += query_sum(1, id[top[x]], id[x], 1, n);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		swap(x, y);
	ans += query_sum(1, id[x] + 1, id[y], 1, n);
	return ans;
}

int range_mx(int x, int y) {
	int ans = -2e9;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		ans = max(ans, query_mx(1, id[top[x]], id[x], 1, n));
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		swap(x, y);
	ans = max(ans, query_mx(1, id[x] + 1, id[y], 1, n));
	return ans;
}

int range_mn(int x, int y) {
	int ans = 2e9;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		ans = min(ans, query_mn(1, id[top[x]], id[x], 1, n));
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		swap(x, y);
	ans = min(ans, query_mn(1, id[x] + 1, id[y], 1, n));
	return ans;
}

int main() {
	int dc, x, y, l;
	char op;
	qr(n);
	for(int i = 1; i < n; i++) {
		qr(x); qr(y); qr(l);
		x++;
		y++;
		add_edge(x, y, l);
		add_edge(y, x, l);
	}
	qr(dc);
	//记住初始化
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	while(dc--) {
		readc(op);
		if(op == 'M')
			readc(op);
		qr(x); qr(y);
		x++; y++;
		if(op == 'C')
			change(1, id[x], 1, n, y - 1);
		if(op == 'N')
			range_update(x, y);
		if(op == 'S') {
			qw(range_sum(x, y));
			putchar('\n');
		}
		if(op == 'A') {
			qw(range_mx(x, y));
			putchar('\n');
		}
		if(op == 'I') {
			qw(range_mn(x, y));
			putchar('\n');
		}
	}
	return 0;
}