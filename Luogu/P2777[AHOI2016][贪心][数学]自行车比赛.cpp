#include <cstdio>
#include <cstdlib>
int a[300005];
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    int n,mx=0,s=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        qr(a[i]);
        if(a[i]>mx)
            mx=a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]+n>mx)
            s++;
    }
    printf("%d",s);
    return 0;
}