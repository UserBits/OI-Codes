#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char src[51][51],ord[10];
int mp[51][51],ans[51][51],n,m;
bool v[51][51];
void bfs(int dir){
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j] && !v[i][j]){
                ans[i][j]=0;
                int nowx=i+d[dir][0],nowy=j+d[dir][1];
                while(mp[nowx][nowy]){
                    ans[nowx][nowy]=1;
                    v[nowx][nowy]=1;
                    nowx+=d[dir][0];
                    nowy+=d[dir][1];
                    if(nowx<1 || nowy<1 || nowx>n || nowy>m)
                        break;
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>src[i][j];
            if(src[i][j]=='*'){
                ans[i][j]=1;
                mp[i][j]=1;
            }
            if(src[i][j]=='.')
                mp[i][j]=1;
        }
    }
    int DC;
    scanf("%d",&DC);
    while(DC--){
        cin>>ord;
        if(ord[0]=='N')
            bfs(0);
        else if(ord[0]=='E')
            bfs(1);
        else if(ord[0]=='S')
            bfs(2);
        else if(ord[0]=='W')
            bfs(3);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j])
                putchar('*');
            else{
                if(src[i][j]=='*')
                    putchar('.');
                else
                    putchar(src[i][j]);
            }
        }
        putchar('\n');
    }
    return 0;
}