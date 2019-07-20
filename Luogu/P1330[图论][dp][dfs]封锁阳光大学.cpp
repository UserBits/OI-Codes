#include <cstdio>
#include <algorithm>

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

const int N=10001,M=200001;
struct Edge{
    int node,next;
}edge[M];
int n,m,tot,head[N],sumx,sumy;
bool v[N],col[N];   

inline void add(int x,int y){
    edge[++tot].node=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

bool dfs(int u,bool color){
    if(v[u]){
        if(col[u]==color)
            return 1;
        else
            return 0;
    }
    v[u]=1;
    col[u]=color;
    if(color)
        sumy++;
    else
        sumx++;
    bool p=1;
    for(int k=head[u];k;k=edge[k].next){
        p=p&&dfs(edge[k].node,1^color);
        if(!p)
            break;
    }   
    return p;
}

int main(){
    qr(n); qr(m);
    int x,y,ans=0;
    while(m--){
        qr(x), qr(y);
        add(x,y); add(y,x);
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            sumx=sumy=0;
            if(!dfs(i,0)){
                puts("Impossible");
                //system("pause");
                return 0;
            }
            ans+=min(sumx,sumy);
        }
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}