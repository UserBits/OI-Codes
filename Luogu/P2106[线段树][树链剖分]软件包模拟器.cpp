#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

using namespace std;

char ss[1 << 17], * A = ss, * B = ss;
inline char gc() {
	return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? EOF : *A++;
}
template<typename qRead>
inline void qr(qRead& s) {
	char c = gc();
	s = 0;
	for(; c < '0' || c > '9'; c = gc());
	for(; c >= '0' && c <= '9'; c = gc())
		s = (s << 1) + (s << 3) + (c - '0');
}
template<typename qWrite>
inline void qw(qWrite s) {
	if(s > 9)
		qw(s / 10);
	putchar(s % 10 + '0');
}

const int N = 100005;
struct Edge {
	int node, next;
}edge[N];
int head[N], add[N << 2], sum[N << 2], n, tot;
inline void add_edge(int x, int y) {
	edge[++tot].node = y;
	edge[tot].next = head[x];
	head[x] = tot;
}

int son[N], id[N], fa[N], dep[N], top[N], siz[N], num;
void dfs1(int u, int f, int d) {
	dep[u] = d;
	fa[u] = f;
	siz[u] = 1;
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
	top[u] = rt;
	id[u] = ++num;
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
}
inline void pushdown(int rt, int ln, int rn) {
	if(add[rt] != -1) {
		sum[rt << 1] = add[rt] * ln;
		sum[rt << 1 | 1] = add[rt] * rn;
		add[rt << 1] = add[rt << 1 | 1] = add[rt];
		add[rt] = -1;
	}
}

void build(int rt, int l, int r) {
	add[rt] = -1;
	if(l == r)
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(mid);
}

void update(int rt, int L, int R, int v, int now_l, int now_r) {
	if(L <= now_l && now_r <= R) {
		sum[rt] = (now_r - now_l + 1) * v;
		add[rt] = v;//覆盖，不是累加
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
	return ans;
}

void range_update(int x, int y, int z) {
	int ans = 0;
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

inline void readc(char& c) {
	c = gc();
	while(c < 'a' || c > 'z')
		c = gc();
}


int main() {
	int dc, x;
	char op;
	qr(n);
	for(int i = 2; i <= n; i++) {
		qr(x);
		add_edge(x + 1, i);
		//依赖关系：单向
	}
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	qr(dc);
	while(dc--) {
		readc(op);
		if(op == 'i') {
			qr(x);
			x++;
			int p = sum[1];
			range_update(1, x, 1);
			int q = sum[1];
			qw(abs(p - q));
			putchar('\n');
		}
		if(op == 'u') {
			qr(x);
			x++;
			int p = sum[1];
			update(1, id[x], id[x] + siz[x] - 1, 0, 1, n);
			int q = sum[1];
			qw(abs(p - q));
			putchar('\n');
		}
	}
	return 0;
}