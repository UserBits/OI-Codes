#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int N=40;
ll f[N][N];
int main(){
    int n,h;
    scanf("%d%d",&n,&h);
    for(int i=0;i<=n;i++)
        f[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<j;k++)
                f[j][i]+=f[k][i-1]*f[j-k-1][i-1];
        }
    }
    cout<<f[n][n]-f[n][h-1]<<endl;
    return 0;
}