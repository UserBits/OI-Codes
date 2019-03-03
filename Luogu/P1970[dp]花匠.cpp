#include <cstdio>
#include <cstdlib>
int a[100001],f[100001],g[100001];
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        qr(a[i]);
    f[1]=g[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1])
            f[i]=g[i-1]+1;
        else
            f[i]=f[i-1];
        if(a[i]<a[i-1])
            g[i]=f[i-1]+1;
        else
            g[i]=g[i-1];
    }
    printf("%d\n",f[n]>g[n]?f[n]:g[n]);
    //system("pause");
    return 0;
}