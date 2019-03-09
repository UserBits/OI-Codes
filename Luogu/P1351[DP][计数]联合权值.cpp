#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N=200001,mod=10007;
struct Edge{
    int node,next;
}edge[N<<1];
int head[N],tot,n,x,y,w[N];
inline void add(int x,int y){
    edge[++tot].node=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    int sum=0,mx=0;
    for(int i=1;i<=n;i++){
        int p=0,q=0,r1=0,r2=0;
        for(int j=head[i];j;j=edge[j].next){
            int k=edge[j].node;
            if(w[k]>r1)
                r2=r1,r1=w[k];
            else if(w[k]>r2)
                r2=w[k];
            p=(p+w[k])%mod;
            q=(q+w[k]*w[k])%mod;
        }
        p=p*p%mod;
        sum=(sum+p-q+mod)%mod;
        if(r1*r2>mx)
            mx=r1*r2;
    }
    printf("%d %d\n",mx,sum);
    //system("pause");
    return 0;
}