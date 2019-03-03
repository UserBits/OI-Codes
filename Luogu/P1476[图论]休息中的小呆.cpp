#include <cstdio>
#include <algorithm>
using namespace std;
int f[105][105];
int main(){
    int n,m,x,y,l;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&x,&y,&l);
        f[x][y]=l;
    }
    for(int k=1;k<=n+1;k++){
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=n+1;j++){
                if(f[i][k]&&f[k][j])
                    f[i][j]=max(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    printf("%d\n",f[1][n+1]);
    for(int k=1;k<=n+1;k++){
        if(f[1][n+1]==f[1][k]+f[k][n+1])
            printf("%d ",k);
    }
    return 0;
}