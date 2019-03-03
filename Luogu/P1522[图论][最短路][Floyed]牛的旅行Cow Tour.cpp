#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
int x[151],y[151],mp[151][151];
double f[151][151],d[151];
double Dis(int i,int j){
    double p=(x[i]-x[j]),q=(y[i]-y[j]);
    return sqrt(p*p+q*q);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&mp[i][j]);
            if(mp[i][j]==1)
                f[i][j]=Dis(i,j);
            else
                f[i][j]=1e9;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j || j==k || i==k || !mp[i][k] || !mp[k][j])
                    continue;
                mp[i][j]=1;
                if(f[i][k]+f[k][j]<f[i][j])
                    f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j] && f[i][j]>d[i])
                d[i]=f[i][j];
        }
    }
    double ans=2e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j && !mp[i][j] && d[i]+Dis(i,j)+d[j]<ans)
                ans=d[i]+Dis(i,j)+d[j];
        }
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,d[i]);
    printf("%.6lf\n",ans);
    return 0;
}