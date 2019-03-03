#include <cstdio>
#include <algorithm>
using namespace std;
int f[10005][105];
/*
    f[i][j]表示在前i秒移动j次获得的最大苹果数
*/
int main(){
    int t,w,x;
    scanf("%d%d",&t,&w);
    for(int i=1;i<=t;i++){
        scanf("%d",&x);
        int tmp=min(w,i); //前i秒最多可移动i次
        for(int j=0;j<=tmp;j++){
            if(!j)
                f[i][j]=f[i-1][j];
            else
                f[i][j]=max(f[i-1][j-1],f[i-1][j]);
            if(x==j%2+1) //移动j次的位置: j%2+1
                f[i][j]++;
        }
    }
    int ans=0;
    for(int i=0;i<=w;i++)
        ans=max(ans,f[t][i]);
    printf("%d\n",ans);
    return 0;
}
