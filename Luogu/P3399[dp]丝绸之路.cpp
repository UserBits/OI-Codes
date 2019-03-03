#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int f[1005][1005],d[1005],c[1005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        f[i][i]=f[i-1][i-1]+d[i]*c[i];
    for(int i=1;i<=n;i++){
        int tmp=i+m-n;
        for(int j=i+1;j<=tmp;j++)
            f[i][j]=min(f[i-1][j-1]+d[i]*c[j],f[i][j-1]);
    }
    printf("%d\n",f[n][m]);
    //system("pause");
    return 0;
}