#include <cstdio>
#include <cstdlib>
using namespace std;
long long f[3000005];
//求1~n的所有整数在mod p情况下的逆元
int main(){
    int n,p;
    scanf("%d%d",&n,&p);
    f[1]=1;
    puts("1");
    for(int i=2;i<=n;i++){
        f[i]=(long long)(p-p/i)*f[p%i]%p;
        printf("%lld\n",f[i]);
    }
    //system("pause");
    return 0;
}