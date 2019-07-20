#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

char ss[1<<17], *A = ss, *B = ss;
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

const int N = 100005, M = 300005, mod = 1e9 + 7;
struct Edge{
    int node, next;
}edge[M];
struct Head{
    int first, cost;
}head[N];
int tot, dfn[N], low[N], mnc[N], cnt[N], color, num;
stack<int> s;
bool ins[N];

inline void add_edge(int x, int y){
    edge[++tot].node = y;
    edge[tot].next = head[x].first;
    head[x].first = tot;
}

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
    if(low[u] == dfn[u]){
        ins[u] = 0;
        mnc[++color] = head[u].cost;
        cnt[color] = 1;
        while(s.top() != u){
            ins[s.top()] = 0;
            if(head[s.top()].cost < mnc[color]){
                mnc[color] = head[s.top()].cost;
                cnt[color] = 1;
            }
            else if(head[s.top()].cost == mnc[color])
                cnt[color]++;
            s.pop();
        }
        s.pop();
    }
}

void work(){
    int n, m, x, y;
    qr(n);
    for(int i = 1; i <= n; i++)
        qr(head[i].cost);
    qr(m);
    while(m--){
        qr(x), qr(y);
        add_edge(x, y);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i])
            tarjan(i);
    }
    //printf("%d\n", color);
    long long sum = 0, ways = 1;
    for(int i = 1; i <= color; i++){
        //printf("[%d]", mnc[i]);
        sum += mnc[i];
        ways = ways * cnt[i] % mod;
    }
    printf("%lld %lld\n", sum, ways);
}

int main(){
    work();
    //system("pause");
    return 0;
}