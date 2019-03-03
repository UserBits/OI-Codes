#include <cstdio>
int a[1000005];
inline int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    int n,k,cnt=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        if(gcd(i,n)==1)
            a[++cnt]=i;
    }
    //在长度为n的任何一段区间内，与n互质的数的个数总是相等的
    int base=(k-1)/cnt*n;
    //有(k-1)/cnt个完整的循环
    int mod=(k-1)%cnt+1;
    //还剩下多少个数
    printf("%d\n",base+a[mod]);
    return 0;
}
