#include <cstdio>
#include <cstdlib>
long long f[1005][1005];
int main(){
    int a,b,k,n,m;
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    f[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0&&j==0)
                continue;
            if(i>0)
                f[i][j]=(f[i][j]+f[i-1][j]*a)%10007;
            if(j>0)
                f[i][j]=(f[i][j]+f[i][j-1]*b)%10007;
        }
    }
    printf("%lld\n",f[n][m]);
    //system("pause");
    return 0;
}