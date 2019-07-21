#include <cstdio>
#include <algorithm>
using namespace std;
int f[250][250];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i][i]);
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n;i++){
            int j=i+l-1;
            if(j>n)
                break;
            for(int k=i;k<j;k++){
                if(f[i][k]==f[k+1][j])
                    f[i][j]=max(f[i][j],f[i][k]+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            ans=max(ans,f[i][j]);
    }
    printf("%d\n",ans);
    return 0;
}