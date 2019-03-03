#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[25005],b[25005];
int main(){
    int n,x,y;
    long long ans=0;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++){
        if(a[i]<b[i])
            ans+=(b[i]-a[i])*x;
        if(a[i]>b[i])
            ans+=(a[i]-b[i])*y;
    }
    printf("%lld\n",ans);
    //system("pause");
    return 0;
}