#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int f[101][101],a[101];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i][i]=a[i];
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n;i++){
            int j=i+l-1;
            if(j>n)
                break;
            f[i][j]=abs(a[i]-a[j])*(j-i+1);
            for(int k=i;k<j;k++)
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
        }
    }
    printf("%d\n",f[1][n]);
    //system("pause");
    return 0;
}