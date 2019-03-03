#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int f[105][105],h[105][105],r,c;
const int d[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int dfs(int x,int y){
    if(f[x][y])
        return f[x][y];
    int tmp=1,tx,ty;
    for(int i=0;i<4;i++){
        tx=x+d[i][0];
        ty=y+d[i][1];
        if(tx>=1&&tx<=r&&ty>=1&&ty<=c&&h[tx][ty]<h[x][y])
            tmp=max(tmp,dfs(tx,ty)+1);
    }
    return f[x][y]=tmp;
}
int main(){
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++)
            scanf("%d",&h[i][j]);
    }
    int ans=1,tmp;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            tmp=dfs(i,j);
            f[i][j]=tmp;
            //printf("[%d]",tmp);
            ans=max(ans,tmp);
        }
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}