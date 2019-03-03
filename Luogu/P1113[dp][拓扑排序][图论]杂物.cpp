#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int f[10005];
int main(){
    int n,l,t,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&i,&l);
        int tmp=0;
        while(scanf("%d",&t)){
            if(!t)
                break;
            tmp=max(tmp,f[t]);
        }
        f[i]=tmp+l;
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans);
    return 0;
}