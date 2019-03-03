#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
const int N=301;
int f[N][N];
int main(){
    int n,m,u,v,l;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&f[i][j]);
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d%d%d",&u,&v,&l);
        if(l<f[u][v]){
            f[u][v]=f[v][u]=l;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j)
                        continue;
                    f[i][j]=min(f[i][j],f[i][u]+f[u][v]+f[v][j]);
                    if(f[i][j]<f[j][i])
                        f[j][i]=f[i][j];
                }
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                sum+=f[i][j];
        }
        cout<<(sum>>1)<<' ';
    }
    return 0;
}