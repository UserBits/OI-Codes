#include <cstdio>
#include <cstdlib>
using namespace std;
int f[1005][1005],a[1005][1005];
int main(){
    int n,m,c,ans=-1<<30,x,y;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
            if(i>=c&&j>=c){
                int tmp=f[i][j]+f[i-c][j-c]-f[i][j-c]-f[i-c][j];
                if(tmp>ans){
                    ans=tmp;
                    x=i-c+1;
                    y=j-c+1;
                }
            }
        }
    }
    printf("%d %d\n",x,y);
    //system("pause");
    return 0;
}