#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>

using namespace std;

char ss[1 << 17], *A = ss, *B = ss;
inline char gc(){
    return A == B && 
        (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? EOF : *A++;
}
template<typename qRead>
inline void qr(qRead &s){
    char c = gc(); 
    s = 0;
    for(; c < '0' || c > '9'; c = gc());
    for(; c >= '0' && c <= '9';c = gc())
        s = (s << 1) + (s << 3) + (c - '0');
}

const int N = 300005;
struct Edge{
    int from, node, next;
}edge[N << 1], graph[N << 1];
int head[N], n, m, tot;
inline void add_edge(int x, int y){
    edge[++tot].from = x;
    edge[tot].next = head[x];
    edge[tot].node = y;
    head[x] = tot;
}

int dfn[N], low[N], col[N], color, num;
bool ins[N];
stack<int> s;
void tarjan(int u, int last){
    dfn[u] = low[u] = ++num;
    s.push(u);
    ins[u] = 1;
    for(int k = head[u]; k; k = edge[k].next){
        int v = edge[k].node;
        if(v == last){
            last = 0;
            continue;
        }
        if(!dfn[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else{
            if(ins[v])
                low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        ins[u] = 0;
        col[u] = ++color;
        while(s.top() != u){
            ins[s.top()] = 0;
            col[s.top()] = color;
            s.pop();
        }
        s.pop();
    }
}

int dis[N];
void bfs(int s){
    queue<int> q;
    q.push(s);
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    int u, v;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int k = head[u]; k; k = graph[k].next){
            v = graph[k].node;
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

void init(){
    qr(n), qr(m);
    int x, y;
    for(int i = 1; i <= m; i++){
        qr(x), qr(y);
        add_edge(x, y), add_edge(y, x);
    }
}

void work(){
    tarjan(1, 0);
    memset(head, 0, sizeof(head));
    tot = 0;
    int x, y;
    for(int i = 1; i <= 2 * m /* 无向边 */; i++){
        x = col[edge[i].from], y = col[edge[i].node];
        if(x != y){
            graph[++tot].node = y;
            graph[tot].next = head[x];
            head[x] = tot;
        }
    }
}

void diameter(){
    int x = 0;
    bfs(1);
    for(int i = 1; i <= color; i++){
        if(dis[i] > dis[x])
            x = i;
    }
    bfs(x);
    x = 0;
    for(int i = 1; i <= color; i++){
        if(dis[i] > dis[x])
            x = i;
    }
    printf("%d\n", dis[x]);
}

int main(){
    init();
    work();
    diameter();
    return 0;
}