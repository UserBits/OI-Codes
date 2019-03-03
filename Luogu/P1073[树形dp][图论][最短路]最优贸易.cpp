#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct Graph{
    int node,next;
}Edge[500001];
int dp[100001],Cost[100001],Need[100001],Head[100001],cnt;
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
inline void add(int x,int y){
    cnt++;
    Edge[cnt].node=y;
    Edge[cnt].next=Head[x];
    Head[x]=cnt;
}
void dfs(int r,int MnCost,int pre){
    bool Exit=1;
    MnCost=min(MnCost,Cost[r]);
    if(MnCost<Need[r]){
        Need[r]=MnCost;
        Exit=0;
    }
    int tmp=max(dp[pre],Cost[r]-MnCost);
    if(tmp>dp[r]){
        dp[r]=tmp;
        Exit=0;
    }
    if(Exit)
        return;
    for(int k=Head[r];k;k=Edge[k].next)
        dfs(Edge[k].node,MnCost,r);
}
int main(){
    int n,m,x,y,l;
    qr(n);  qr(m);
    for(int i=1;i<=n;i++)
        qr(Cost[i]);
    while(m--){
        qr(x);  qr(y);  qr(l);
        add(x,y);
        if(l==2)
            add(y,x);
    }
    /*
    for(int i=1;i<=n;i++){
        printf("Edges of %d: \n",i);
        for(int j=Head[i];j;j=Edge[j].next)
            printf("%d ",Edge[j].node);
        puts("");
    }*/
    memset(Need,127,sizeof(Need));
    dfs(1,2e9,0);
    printf("%d\n",dp[n]);
    //system("pause");
    return 0;
}