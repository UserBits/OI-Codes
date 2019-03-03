#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int f[30005],a[35];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);//防止漏算、重算
        int ans=0;
        for(int i=3;i<=n;i++){ //至少有3个数才能组成加等式
            memset(f,0,sizeof(f)); //f[i]表示和为i时”加等式“的个数
            f[0]=1;
            for(int j=1;j<i;j++){ //不同的组合方式
                for(int k=a[i];k>=a[j];k--)
                    f[k]+=f[k-a[j]];
            }
            ans+=f[a[i]];//累计和为a[i]的方案数
        }
        printf("%d\n",ans);
    }
    return 0;
}
