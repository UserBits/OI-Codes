#include <cstdio>
#include <cstdlib>
inline int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    int n,x,s=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(x<0)
            x=-x;
        s=gcd(x,s);
    }
    printf("%d",s);
    return 0;
}