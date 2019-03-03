#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int a[5005],b[5005];
long long f[5005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==1)
                f[j]+=abs(a[i]-b[j]);
            else
                f[j]=min(f[j-1],f[j]+abs(a[i]-b[j]));
        }
    }
    printf("%lld\n",f[n]);
    return 0;
}