#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int f[15][15],n,sum,r[15];
bool v[15],flag;
void dfs(int dep,int ans){
    if(ans>sum)
        return;
    if(dep>n){
        if(ans==sum)
            flag=1;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            r[dep]=i;
            v[i]=1;
            dfs(dep+1,ans+f[n][dep]*i);
            if(flag)
                return;
            v[i]=0;
        }
    }
}
int main(){
    scanf("%d%d",&n,&sum);
    f[1][1]=1;
    for(int i=2;i<=n;i++){
        f[i][1]=1;
        for(int j=2;j<=n;j++)
            f[i][j]=f[i-1][j]+f[i-1][j-1];
    }
    dfs(1,0);
    if(!flag)
        return 0;
    for(int i=1;i<=n;i++)
        printf("%d ",r[i]);
    //system("pause");
    return 0;
}