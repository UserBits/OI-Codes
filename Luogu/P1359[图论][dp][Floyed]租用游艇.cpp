#include<cstdio>
#include<algorithm>
#include<cstring>
int f[205][205],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            f[i][j]=1e9;
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            scanf("%d",&f[i][j]);
    for(int k=2;k<n;k++)
        for(int i=1;i<k;i++)
            for(int j=k+1;j<=n;j++)
                f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
    printf("%d",f[1][n]);
    return 0;
}