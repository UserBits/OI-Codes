#include <cstdio>
#include <cstdlib>
using namespace std;
bool f[105][105];
int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        f[a][b]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                f[i][j]=f[i][j]||(f[i][k]&&f[k][j]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(i!=j)
                flag=flag&&(f[i][j]||f[j][i]);
        }
        ans+=flag;
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}