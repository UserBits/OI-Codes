#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
const int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,stx,sty,edx,edy,dp[35][35][5],ans=2e9;
bool v[35][35][5];
char mp[35][35];
inline void dfs(int x,int y,int l,int sum){
    if(sum>=ans || sum>=dp[x][y][l])
        return;
    if(x==edx&&y==edy){
        ans=sum;
        return;
    }
    dp[x][y][l]=sum;
    bool flag=0;
    int p,q;
    for(int i=0;i<4;i++){
        p=x+d[i][0];
        q=y+d[i][1];
        if(p>0 && q>0 && p<=n && q<=m && !v[p][q][i] && mp[p][q]!='.'){
            v[p][q][i]=1;
            if((i+1)%4==l){
                flag=1;
                dfs(p,q,i,sum+1);
            }
            if((l+1)%4==i){
                flag=1;
                dfs(p,q,i,sum+5);
            }
            if(l==i){
                flag=1;
                dfs(p,q,i,sum);
            }
            v[p][q][i]=0;
        }
    }
    if(!flag){
        p=x+d[(l+2)%4][0];
        q=y+d[(l+2)%4][1];
        if(p>0 && q>0 && p<=n && q<=m && !v[p][q][(l+2)%4] && mp[p][q]!='.'){
            v[p][q][(l+2)%4]=1;
            dfs(p,q,(l+2)%4,sum+10);
            v[p][q][(l+2)%4]=0;
        }
    }
}
int main(){
    cin>>n>>m;
    int stl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]>='A' && mp[i][j]<='Z' && mp[i][j]!='F'){
                stx=i;
                sty=j;
                if(mp[i][j]=='N')
                    stl=0;
                if(mp[i][j]=='E')
                    stl=1;
                if(mp[i][j]=='S')
                    stl=2;
                if(mp[i][j]=='W')
                    stl=3;
            }
            if(mp[i][j]=='F'){
                edx=i;
                edy=j;
            }
        }
    }
    v[stx][sty][stl]=1;
    memset(dp,0x7f,sizeof(dp));
    dfs(stx,sty,stl,0);
    printf("%d\n",ans);
    return 0;
}