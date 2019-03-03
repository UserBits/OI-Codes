#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename qRead>
inline void qr(qRead &s){
    char c=gc();
    s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
}

const int N=1001,M=1000001;
struct edge{
    int node,next;
}Edge[M];
struct head{
    int first,deg;
}Head[N];
int n,tot,ans=1,a[N];
bool p[N][N],sta[N];
struct qNode{
    int key,dep;
};

inline void Add(int x,int y){
    Edge[++tot].node=y;
    Edge[tot].next=Head[x].first;
    Head[x].first=tot;
    Head[y].deg++;
}

void TopSort(){
    queue<qNode> q;
    for(int i=1;i<=n;i++){
        if(!Head[i].deg)
            q.push((qNode){i,1});
    }
    qNode r; int v;
    while(!q.empty()){
        r=q.front(); q.pop();
        for(int k=Head[r.key].first;k;k=Edge[k].next){
            v=Edge[k].node; Head[v].deg--;
            if(!Head[v].deg){
                q.push((qNode){v,r.dep+1});
                ans=max(ans,r.dep+1);
            }
        }
    }
}

int main(){
    int m,x;
    qr(n); qr(m);
    while(m--){
        qr(x);
        memset(sta,0,sizeof(sta));
        for(int i=1;i<=x;i++){
            qr(a[i]); sta[a[i]]=1;
        }
        for(int i=a[1];i<=a[x];i++){
            if(sta[i]) continue;
            for(int j=1;j<=x;j++){
                if(!p[i][a[j]]){
                    p[i][a[j]]=1;
                    Add(i,a[j]);
                }
            }
        }
    }
    TopSort();
    printf("%d\n",ans);
    return 0;
}