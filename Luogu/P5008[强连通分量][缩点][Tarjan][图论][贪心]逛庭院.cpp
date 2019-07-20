#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
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

const int N = 500005, M = 2000005;
struct Edge{
    int node, next, from;
}edge[M];
int n, m, k, tot, ind[N];
struct Head{
    int first, fire, id;
}head[N];

inline void add_edge(int x, int y){
    edge[++tot].node = y;
    edge[tot].next = head[x].first;
    edge[tot].from = x;
    head[x].first = tot;
}

int dfn[N], low[N], col[N], color, num;
stack<int> s;
bool ins[N];

void tarjan(int u){
    dfn[u] = low[u] = ++num;
    s.push(u);
    ins[u] = 1;
    for(int k = head[u].first; k; k = edge[k].next){
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
    if(dfn[u] == low[u]){
        col[u] = ++color;
        ins[u] = 0;
        while(s.top() != u){
            col[s.top()] = color;
            ins[s.top()] = 0;
            s.pop();
        }
        s.pop();
    }
}

void init(){
    qr(n), qr(m), qr(k);
    int x, y;
    for(int i = 1; i <= n; i++){
        qr(head[i].fire);
        head[i].id = i;
    }
    for(int i = 1; i <= m; i++){
        qr(x), qr(y);
        add_edge(x, y);
    }
}

bool cmp(Head x, Head y){
    return x.fire < y.fire;
}

void work(){
    for(int i = 1; i <= n; i++){
        if(!dfn[i])
            tarjan(i);
    }
    for(int i = 1; i <= m; i++){
        int x = col[edge[i].node], y = col[edge[i].from];
        if(x != y)
            ind[x]++;
    }
    sort(head + 1, head + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        int x = head[i].id;
        if(!ind[col[x]])
            head[i].fire = 0, ind[col[x]] = 1;
    }
    int ans = 0;
    for(int i = n; i; i--){
        if(head[i].fire)
            ans += head[i].fire, k--;
        if(!k)
            break;
    }
    printf("%d\n", ans);
}

int main(){
    init();
    work();
    //system("pause");
    return 0;
}