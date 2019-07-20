#include <cstdio>
#include <queue>

using namespace std;

const int N = 100005;
int n, m;

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

namespace Graph{

    struct Edge{
        int node, next, length;
    }edge[N * 3];
    int head[N], tot;

    inline void add_edge(int x, int y, int l){
        edge[++tot].node = y;
        edge[tot].next = head[x];
        edge[tot].length = l;
        head[x] = tot;
    }

}

int vis_cnt[N], dis[N];
bool inq[N];
queue<int> q;

bool spfa(){
    int u, v;
    while(!q.empty()){
        u = q.front();
        q.pop();
        inq[u] = 0;
        if(vis_cnt[u] == n - 1)
            return false;
        vis_cnt[u]++;
        for(int k = Graph :: head[u]; k; k = Graph :: edge[k].next){
            v = Graph :: edge[k].node;
            if(dis[u] + Graph :: edge[k].length > dis[v]){
                dis[v] = dis[u] + Graph :: edge[k].length;
                if(!inq[v]){
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

void work(){
    qr(n), qr(m);
    int flag, x, y;
    while(m--){
        qr(flag), qr(x), qr(y);
        switch(flag){
            case 1:{
                Graph :: add_edge(x, y, 0), Graph :: add_edge(y, x, 0);
                break;
            }
            case 2:{
                if(x == y){
                    puts("-1");     return;
                }
                Graph :: add_edge(x, y, 1);
                break;
            }
            case 3:{
                Graph :: add_edge(y, x, 0);     break;
            }
            case 4:{
                if(x == y){
                    puts("-1");     return;
                }
                Graph :: add_edge(y, x, 1);
                break;
            }
            case 5:{
                Graph :: add_edge(x, y, 0);     break;
            }
        }
    }
    for(int i = n; i > 0; i--)
        Graph :: add_edge(n + 1, i, 1);
    q.push(n + 1);
    inq[n + 1] = 1;
    if(!spfa()){
        puts("-1");
        return;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        ans += dis[i];
    printf("%lld\n", ans);
}

int main(){
    work();
    return 0;
}
