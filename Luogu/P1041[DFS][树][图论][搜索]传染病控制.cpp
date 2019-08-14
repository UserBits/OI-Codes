#include <cstdio>
#include <cstdlib>

char ss[1 << 17], *A = ss, *B = ss;
inline char gc(){
    return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B)
		   ? EOF : *A++;
}
template<typename qRead>
inline void qr(qRead &s){
    char c = gc();
    s = 0;
    for(; c < '0' || c > '9'; c = gc());
    for(; c >= '0' && c <= '9'; c = gc())
        s = (s << 1) + (s << 3) + (c - '0');
}

const int N = 305;
struct Edge{
	int node, next;
}edge[N];
int head[N], n, p, tot;
inline void add_edge(int x, int y){
	edge[++tot].node = y;
	edge[tot].next = head[x];
	head[x] = tot;
}

struct Dep{
	int num, a[N];
}dep[N];
int depth, cnt[N], ans = 1e9;
bool vis[N];

void init(){
	qr(n), qr(p);
	int x, y;
	while(p--){
		qr(x), qr(y);
		if(x > y)
			x ^= y ^= x ^= y;
		//printf("[%d %d]\n",x,y);
		add_edge(x, y);
	}
}

void getdep(int u, int d){
	if(d > depth)
		depth = d;
	for(int k = head[u]; k; k = edge[k].next){
		dep[d + 1].a[++dep[d + 1].num] = edge[k].node;
		getdep(edge[k].node, d + 1);
	}
}

int getsize(int u){
	for(int k = head[u]; k; k = edge[k].next)
		cnt[u] += getsize(edge[k].node);
	return cnt[u];
}

void sign(int u, int sta){
	for(int k = head[u]; k; k = edge[k].next){
		vis[edge[k].node] = sta;
		sign(edge[k].node, sta);
	}
}

void dfs(int u, int all){
	//printf("[%d : %d : %d]\n",u,all,ans);
	if(u > depth){
		if(all < ans)
			ans = all;
		return;
	}
	int sum = 0;
	for(int i = 1; i <= dep[u].num; i++){
		if(vis[dep[u].a[i]]){
			sum++;
			continue;
		}
		//printf("[%d]\n",dep[u].a[i]);
		vis[dep[u].a[i]] = 1;
		sign(dep[u].a[i], 1);
		dfs(u + 1, all - cnt[dep[u].a[i]]);
		vis[dep[u].a[i]] = 0;
		sign(dep[u].a[i], 0);
	}
	if(sum == dep[u].num && all < ans)
		ans = all;
}

int main(){
	init();
	getdep(1, 1);
	/*printf("dep: %d\n",depth);
	for(int i=1;i<=depth;i++){
		for(int j=1;j<=dep[i].num;j++)
			printf("[%d]",dep[i].a[j]);
		puts("");
	}*/
	for(int i = 1; i < N; i++)
		cnt[i] = 1;
	getsize(1);
	/*for(int i = 1; i <= n; i++)
		printf("[%d]",cnt[i]);
	puts("");*/
	dfs(2, n);
	printf("%d\n", ans);
	return 0;
}
