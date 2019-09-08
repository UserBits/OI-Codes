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
}edge[N << 1]; //树边：无向边
struct Head {
	int first, val;
}head[N];
int tot, a[N], add[N << 2], sum[N << 2], n, p;
//a: 展开为序列后的点权（线段树初始权值）

inline void add_edge(int x, int y) {
	edge[++tot].node = y;
	edge[tot].next = head[x].first;
	head[x].first = tot;
}

int son[N], id[N], fa[N], dep[N], siz[N], top[N], num;
/*
son: 重儿子		id: 新编号
fa: 父节点		dep: 深度
size: 子树大小	top: 当前链的顶端（根）节点
num: dfs序
*/

void dfs1(int u, int f, int d) { //处理dep,son,fa,siz
	dep[u] = d;
	fa[u] = f;
	siz[u] = 1;
	for(int k = head[u].first, v; k; k = edge[k].next) {
		v = edge[k].node;
		if(v == f)
			continue;
		dfs1(v, u, d + 1); //搜索子节点
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]])
			son[u] = v;
	}
}

void dfs2(int u, int rt) { //处理id,a,top
	id[u] = ++num;
	a[num] = head[u].val;
	top[u] = rt;
	if(!son[u]) { //叶节点
		return;
	}
	dfs2(son[u], rt);
	for(int k = head[u].first, v; k; k = edge[k].next) {
		v = edge[k].node;
		if(v == fa[u] || v == son[u]) //避免重复计算
			continue;
		dfs2(v, v);
	}
}

inline void pushup(int rt) {
	sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % p;
}
inline void pushdown(int rt, int ln, int rn) {
	if(add[rt]) {
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += add[rt] * ln;
		sum[rt << 1 | 1] += add[rt] * rn;
		add[rt << 1] %= p, add[rt << 1 | 1] %= p;
		sum[rt << 1] %= p, sum[rt << 1 | 1] %= p;
		add[rt] = 0;
	}
}

void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = a[l] % p;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int L, int R, int v, int now_l, int now_r) {
	if(now_l >= L && now_r <= R) {
		add[rt] += v;
		sum[rt] += (now_r - now_l + 1) * v;
		add[rt] %= p, sum[rt] %= p;
		return;
	}
	int mid = (now_l + now_r) >> 1;
	pushdown(rt, mid - now_l + 1, now_r - mid);
	if(L <= mid)
		update(rt << 1, L, R, v, now_l, mid);
	if(R > mid)
		update(rt << 1 | 1, L, R, v, mid + 1, now_r);
	pushup(rt);
}

int query(int rt, int L, int R, int now_l, int now_r) {
	if(now_l >= L && now_r <= R) {
		return sum[rt];
	}
	int mid = (now_l + now_r) >> 1;
	pushdown(rt, mid - now_l + 1, now_r - mid);
	int ans = 0;
	if(L <= mid)
		ans += query(rt << 1, L, R, now_l, mid), ans %= p;
	if(R > mid)
		ans += query(rt << 1 | 1, L, R, mid + 1, now_r), ans %= p;
	return ans;
}

int range_query(int x, int y) { //询问树上x到y
	int ans = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		ans += query(1, id[top[x]], id[x], 1, n);
		ans %= p;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		swap(x, y);
	ans += query(1, id[x], id[y], 1, n);
	return ans % p;
}

void range_update(int x, int y, int z) { //更新树上x到y
	z %= p;
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

int subtree_query(int x) { //询问子树x
	return query(1, id[x], id[x] + siz[x] - 1, 1, n);
}

void subtree_update(int x, int y) { //更新子树x
	y %= p;
	update(1, id[x], id[x] + siz[x] - 1, y, 1, n);
}

void work() {
	int dc, root, op, x, y, z;
	qr(n); qr(dc); qr(root); qr(p); //模数
	for(int i = 1; i <= n; i++) //初始权值
		qr(head[i].val);
	for(int i = 1; i < n; i++) {
		qr(x); qr(y);
		add_edge(x, y);
		add_edge(y, x);
	}
	dfs1(root, 0, 1);
	dfs2(root, root);
	build(1, 1, n);
	while(dc--) {
		qr(op);
		if(op == 1) {
			qr(x); qr(y); qr(z);
			range_update(x, y, z);
		}
		if(op == 2) {
			qr(x); qr(y);
			qw(range_query(x, y));
			putchar('\n');
		}
		if(op == 3) {
			qr(x); qr(y);
			subtree_update(x, y);
		}
		if(op == 4) {
			qr(x);
			qw(subtree_query(x));
			putchar('\n');
		}
	}
}

int main() {
	work();
	return 0;
}
