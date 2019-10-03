#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int N = 1005, M = 1000005;
struct Edge {
	int node, next, val;
}edge[M];
int n, m, tot, head[N], pre[N], nxt[N];
inline void add_edge(int x, int y, int l) {
	edge[++tot].node = y;
	edge[tot].next = head[x];
	edge[tot].val = l;
	head[x] = tot;
}

double dis[N];
bool inq[N];
queue<int> q;
void spfa() {
	for(int i = 1; i < N; i++)
		dis[i] = 1e9;
	dis[1] = 0;
	inq[1] = 1;
	q.push(1);
	int u, v;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		inq[u] = 0;
		for(int k = head[u]; k; k = edge[k].next) {
			v = edge[k].node;
			if(dis[u] + log(edge[k].val) < dis[v]) {
				dis[v] = dis[u] + log(edge[k].val);
				pre[v] = u;
				if(!inq[v]) {
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int x, y, l;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &l);
		add_edge(x, y, l);
	}
	spfa();
	x = n;
	while(x != 1) {
		nxt[pre[x]] = x;
		x = pre[x];
	}
	x = 1;
	int ans = 1;
	while(x != n) {
		for(int k = head[x]; k; k = edge[k].next) {
			y = edge[k].node;
			if(y == nxt[x])
				ans = ans * edge[k].val % 9987;
		}
		x = nxt[x];
	}
	printf("%d\n", ans);
	return 0;
}