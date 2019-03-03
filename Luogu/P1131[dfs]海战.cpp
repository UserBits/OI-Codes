#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
char s[1005][1005];
const int d[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int n,m;
bool check(int x,int y)
{
    int cnt=0;
    cnt+=(s[x][y]=='#');
    cnt+=(s[x+1][y]=='#');
    cnt+=(s[x][y+1]=='#');
    cnt+=(s[x+1][y+1]=='#');
    if(cnt==3)
        return 0;
    else
        return 1;
}
inline void dfs(int x,int y){
    s[x][y]='.';
    int tx,ty;
    for(int i=0;i<4;i++)
    {
        tx=x+d[i][0];
        ty=y+d[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&s[tx][ty]=='#')
            dfs(tx,ty);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cin>>s[i][j];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(!check(i,j)){
                puts("Bad placement.");
                return 0;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='#'){
                ans++;
                dfs(i,j);
            }
        }
    }
    printf("There are %d ships.\n",ans);
    return 0;
}

