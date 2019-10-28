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

const int N = 30005;
struct Edge {
	int node, next;
}edge[N << 1];
struct Head {
	int first, val;
}head[N];
int n, tot, a[N], sum[N << 2], mx[N << 2];
inline void add_edge(int x, int y) {
	edge[++tot].node = y;
	edge[tot].next = head[x].first;
	head[x].first = tot;
}

int son[N], top[N], id[N], fa[N], dep[N], siz[N], num;
void dfs1(int u, int f, int d) {
	fa[u] = f;
	dep[u] = d;
	siz[u] = 1;
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
	top[u] = rt;
	id[u] = ++num;
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

inline void pushup(int u) {
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
	mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
}
void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = mx[rt] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		mx[rt] = sum[rt] = val;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

pair<int, int> query(int rt, int L, int R, int now_l, int now_r) {
	if(L <= now_l && now_r <= R)
		return make_pair(sum[rt], mx[rt]);
	int mid = now_l + now_r >> 1;
	pair<int, int> ans = make_pair(0, -1e9), tp;
	if(L <= mid) {
		tp = query(rt << 1, L, R, now_l, mid);
		ans.first += tp.first;
		ans.second = max(ans.second, tp.second);
	}
	if(R > mid) {
		tp = query(rt << 1 | 1, L, R, mid + 1, now_r);
		ans.first += tp.first;
		ans.second = max(ans.second, tp.second);
	}
	pushup(rt);
	return ans;
}

pair<int, int> range_query(int x, int y) {
	pair<int, int> ans = make_pair(0, -1e9), tp;
	while(top[x] ^ top[y]) {
		if(dep[top[x]] < dep[top[y]])
			x ^= y ^= x ^= y;
		tp = query(1, id[top[x]], id[x], 1, n);
		ans.first += tp.first;
		ans.second = max(ans.second, tp.second);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])
		x ^= y ^= x ^= y;
	tp = query(1, id[x], id[y], 1, n);
	ans.first += tp.first;
	ans.second = max(ans.second, tp.second);
	return ans;
}

int main() {
	int x, y, q;
	pair<int, int> t;
	char op;
	qr(n);
	for(int i = 1; i < n; i++) {
		qr(x); qr(y);
		add_edge(x, y);
		add_edge(y, x);
	}
	//printf("tot = %d\n", tot);
	for(int i = 1; i <= n; i++)
		qr(head[i].val);
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	qr(q);
	//printf("q = %d\n", q);
	while(q--) {
		readc(op);
		if(op == 'C') {
			qr(x); qr(y);
			update(1, 1, n, id[x], y);
		}
		else {
			readc(op); qr(x); qr(y);
			//printf("[Querying: ] %d, %d\n", x, y);
			t = range_query(x, y);
			if(op == 'M'){
				//printf("QMAX = ");
				qw(t.second);
			}
			else{
				//printf("QSUM = ");
				qw(t.first);
			}
			putchar('\n');
		}
	}
	return 0;
}

