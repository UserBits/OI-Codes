// luogu-judger-enable-o2
#include <iostream>
#include <cmath>
using namespace std;
int a[35],i,j;
long long s=0;
int main(){
    while(~scanf("%d",&a[i++]));
    for(j=0;j<i;j++)
        s+=a[j];
    s*=pow(2,i-2);
    printf("%lld\n",s);
    return 0;
}
