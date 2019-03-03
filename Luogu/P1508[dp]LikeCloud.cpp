#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[205][205];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=max(max(a[i-1][j-1],a[i-1][j+1]),a[i-1][j]);
        }
    }
    m=(m+1)>>1;
    printf("%d\n",max(max(a[n][m-1],a[n][m+1]),a[n][m]));
    //system("pause");
    return 0;
}