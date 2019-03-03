#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int f[101][101],t[101][101];
int main(){
    int n,m,x,y,d;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            f[i][j]=t[i][j]=1e9;
    }
    while(m--){
        scanf("%d%d%d",&x,&y,&d);
        t[x][y]=t[y][x]=d;
        f[x][y]=f[y][x]=0;
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&x,&y);
        f[x][y]=f[y][x]=t[x][y];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    scanf("%d%d",&x,&y);
    printf("%d\n",f[x][y]);
    //system("pause");
    return 0;
}