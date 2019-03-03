#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    int n,x,l=0;
    scanf("%d",&n);
    long long sum=0;
    while(n--){
        scanf("%d",&x);
        if(x>l)
            sum+=x-l;
        l=x;
    }
    printf("%lld\n",sum);
    return 0;
}