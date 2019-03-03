#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int f[205][205],t[205];
int main(){
    int n,m,q,x,y,l;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    memset(f,-1,sizeof(f));
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&l);
        x++;
        y++;
        f[x][y]=f[y][x]=l;
    }
    for(int i=1;i<=n;i++)
        f[i][i]=0;
    scanf("%d",&q);
    int p=1;
    while(q--){
        scanf("%d%d%d",&x,&y,&l);
        x++;
        y++;
        if(t[x]>l || t[y]>l){
            puts("-1");
            continue;
        }
        for(;p<=n && t[p]<=l;p++){
            for(int i=1;i<=n;i++){
                if(f[i][p]==-1)
                    continue;
                for(int j=1;j<=n;j++){
                    if(f[p][j]!=-1 && (f[i][j]==-1 || f[i][p]+f[p][j]<f[i][j]))
                        f[i][j]=f[i][p]+f[p][j];
                }
            }
        }
        printf("%d\n",f[x][y]);
    }
    return 0;
}