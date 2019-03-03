#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int now,to;
}edge[100001];
int head[100001],cnt,s[100001];
inline void add(int x,int y){
    cnt++;
    edge[cnt].now=y;
    edge[cnt].to=head[x];
    head[x]=cnt;
}
inline void dfs(int r,int val){
    s[r]=val;
    for(int k=head[r];k;k=edge[k].to){
        if(!s[edge[k].now])
            dfs(edge[k].now,val);
    }
}
int main(){
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        add(y,x); //反向建边
    }
    for(int i=n;i;i--){
        if(!s[i])//从当前点开始搜索，在当前联通块中，当前点一定最大
            dfs(i,i);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",s[i]);
    //system("pause");
    return 0;
}