#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int p[25][25],q[25][25],n,ans=0,t[25];
bool v[25];
inline void dfs(int depth,int sum){
    if(depth>n){
        ans=max(ans,sum);
        return;
    }
    int tmp=0;
    for(int i=depth;i<=n;i++)
        tmp+=t[i];
    if(tmp+sum<ans)
        return;
    for(int i=1;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            dfs(depth+1,sum+p[depth][i]*q[i][depth]);
            v[i]=0;
        }
    }
}
int main(){
    //freopen("testdata.in","r",stdin);
    //freopen("testdata.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&p[i][j]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&q[i][j]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            t[i]=max(t[i],p[i][j]*q[j][i]);
    }
    dfs(1,0);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}