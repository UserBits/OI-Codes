#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[5005],f[5005],g[5005];
//g[i]记录以i结尾最长下降子序列的个数
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0,sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]>a[i])
                f[i]=max(f[i],f[j]+1);
        }
        if(!f[i])
            f[i]=1;
        ans=max(ans,f[i]);
        for(int j=1;j<i;j++){
            if(f[i]==f[j] && a[i]==a[j])
                g[j]=0;  //去重；即：数列前一段相等，只计算一次
            if(a[j]>a[i] && f[i]==f[j]+1)
                g[i]+=g[j];
        }
        if(!g[i])
            g[i]=1; //本身就是最长下降子序列
    }
    for(int i=1;i<=n;i++){
        if(f[i]==ans)
            sum+=g[i];
    }
    printf("%d %d\n",ans,sum);
    //system("pause");
    return 0;
}