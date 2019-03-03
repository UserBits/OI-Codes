#include <cstdio>
#include <cstdlib>
using namespace std;
int f[33000][5];
int main(){
    int t,n=32768;
    f[0][0]=1;
    for(int i=1;i*i<=n;i++){
        for(int j=i*i;j<=n;j++){
            for(int k=1;k<=4;k++)
                f[j][k]+=f[j-i*i][k-1];
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",f[n][1]+f[n][2]+f[n][3]+f[n][4]);
    }
    //system("pause");
    return 0;
}