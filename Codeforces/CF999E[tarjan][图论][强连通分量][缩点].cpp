#include <cstdio>
#include <algorithm>
#include <stack>

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

const int N = 5001;
struct Edge{
    int node, next, from;
}edge[N];
int head[N], n, m, st, tot, ind[N];

inline void add_edge(int x, int y){
    edge[++tot].node = y;
    edge[tot].next = head[x];
    edge[tot].from = x;
    head[x] = tot;
}

int dfn[N], low[N], col[N], color, num;
stack<int> s;
bool ins[N];
void tarjan(int u){
    dfn[u] = low[u] = ++num;
    ins[u] = 1;
    s.push(u);
    for(int k = head[u]; k; k = edge[k].next){
        int v = edge[k].node;
        if(!dfn[v]){
            tarjan(v);
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

int main(){
    qr(n), qr(m), qr(st);
    int x, y;
    for(int i = 1; i <= m; i++){
        qr(x), qr(y);
        add_edge(x, y);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i])
            tarjan(i);
    }
    for(int i = 1; i <= m; i++){
        int x = col[edge[i].from], y = col[edge[i].node];
        if(x != y)
            ind[y]++;
    }
    int ans = 0;
    for(int i = 1; i <= color; i++){
        if(i == col[st])   
            continue;
        if(ind[i] == 0)
            ans++;
    }
    printf("%d\n", ans);
}