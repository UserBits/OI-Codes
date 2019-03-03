#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int f[10005][105],g[10005],lesson[10005][105],ski[105];
int main(){
    //freopen("ski.in","r",stdin);
    //freopen("ski.out","w",stdout);
    int t,s,n;
    scanf("%d%d%d",&t,&s,&n);
    int m,l,a,c,d;
    for(int i=1;i<=s;i++){
        scanf("%d%d%d",&m,&l,&a);
        lesson[m+l-1][a]=max(lesson[m+l-1][a],m);
    }
    memset(ski,0x7f,sizeof(ski));
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c,&d);
        for(int j=c;j<=100;j++)
            ski[j]=min(ski[j],d);
    }
    memset(f,128,sizeof(f));
    f[0][1]=g[0]=0;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=100;j++){
            f[i][j]=f[i-1][j];
            if(lesson[i-1][j])
                f[i][j]=max(f[i][j],g[lesson[i-1][j]]);
            if(i>=ski[j])
                f[i][j]=max(f[i][j],f[i-ski[j]][j]+1);
            g[i]=max(g[i],f[i][j]);
        }
    }
    printf("%d\n",g[t]);
    //system("pause");
    return 0;
}