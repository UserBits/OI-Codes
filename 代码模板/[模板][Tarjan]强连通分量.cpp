#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstdlib>
using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename Tp>
inline void qr(Tp &s){
    char c=gc(); s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
}

const int N=100001,M=500001;
struct edge{
    int node,next;
}Edge[M];
int Head[N],tot;
inline void Add(int x,int y){
    Edge[++tot].node=y; Edge[tot].next=Head[x];
    Head[x]=tot;
}

int dfn[N],low[N],col[N],num,color;
stack<int> s;
bool ins[N];
void tarjan(int u){
    dfn[u]=low[u]=++num;
    ins[u]=1; s.push(u);
    for(int k=Head[u];k;k=Edge[k].next){
        int v=Edge[k].node;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else{
            if(ins[v])
                low[u]=min(low[u],low[v]);
        }
    }
    if(dfn[u]==low[u]){
        col[u]=++color; ins[u]=0;
        while(s.top()!=u){
            col[s.top()]=color;
            ins[s.top()]=0; s.pop();
        }
        s.pop();
    }
}

int main(){
    int n,m,x,y;
    qr(n); qr(m);
    while(m--){
        qr(x); qr(y);
        Add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    printf("Total of groups: %d\n",color);
    for(int i=1;i<=n;i++)
        printf("Point %d belongs to Group %d\n",i,col[i]);
    system("pause");
    return 0;
}
/*
input #1
6 8
1 3
3 5
5 6
2 4
4 6
1 2
3 4
4 1
output #1
Total of groups: 3
Point 1 belongs to Group 3
Point 2 belongs to Group 3
Point 3 belongs to Group 3
Point 4 belongs to Group 3
Point 5 belongs to Group 2
Point 6 belongs to Group 1
*/
/*
input #2
5 5
1 2
2 3
3 4
4 5
5 1
output #2
Total of groups: 1
Point 1 belongs to Group 1
Point 2 belongs to Group 1
Point 3 belongs to Group 1
Point 4 belongs to Group 1
Point 5 belongs to Group 1
*/