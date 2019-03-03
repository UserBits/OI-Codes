#include <cstdio>
#include <cstring>
#include <cstdlib>
const int N=100005,M=400005;
struct edge{
    int node,next;
}Edge[M];
int Head[N],tot,a,b,p;
int v[N];
inline void Add(int x,int y){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Head[x]=tot;
}
void dfs(int x){
    v[x]=1;
    for(int k=Head[x];k;k=Edge[k].next){
        if(!v[Edge[k].node])
            dfs(Edge[k].node);
    }
}
int main(){
    scanf("%d%d%d",&a,&b,&p);
    for(int i=2;i<=b;i++){
        if(!v[i]){
            for(int j=i*2;j<=b;j+=i){
                if(j>=a && i>=p)
                    Add(j,i),Add(i,j);
                v[j]=1;
            }
        }
    }
    for(int i=a;i<=b;i++)
        v[i]=0;
    int ans=0;
    for(int i=a;i<=b;i++){
        if(!v[i]){
            dfs(i);
            ans++;
        }
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}