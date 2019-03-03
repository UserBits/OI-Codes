#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int a[4001],b[4001],f[4001][4001];
//a[i]、b[i]记录位置
//f[i][j]记录将a序列的前i个修改为b序列的前j个的最小花费
int main(){
    int n,x,y,z,p,q,len1=0,len2=0;
    qr(n);  qr(x);  qr(y);  qr(z);
    for(int i=1;i<=n;i++){
        qr(p);
        qr(q);
        while(p--)
            a[++len1]=i;
        while(q--)
            b[++len2]=i;
    }
    for(int i=1;i<=len2;i++)
        f[0][i]=i*x;
    for(int i=1;i<=len1;i++)
        f[i][0]=i*y;
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++)
            f[i][j]=min(min(f[i-1][j]+y,f[i][j-1]+x),f[i-1][j-1]+z*abs(a[i]-b[j]));
    }
    printf("%d\n",f[len1][len2]);
    //system("pause");
    return 0;
}