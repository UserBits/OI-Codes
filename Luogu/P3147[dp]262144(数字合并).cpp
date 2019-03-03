#include <cstdio>
#include <cstdlib>
using namespace std;
int n,f[60][270000];
//f[i][j]表示以j为左端点和为i时的右端点位置
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    int x,ans,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        qr(x);
        f[x][i]=i+1;
    }
    for(i=1;i<=58;++i){
        for(j=1;j<=n;++j){
            if(!f[i][j])
                f[i][j]=f[i-1][f[i-1][j]];
            if(f[i][j])
                ans=i;
        }
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}