#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N=55;
int f[N][N],n;
char a[N];
int dfs(int l,int r){
    if(l==r)
        return f[l][r]=1;
    if(f[l][r]!=-1)
        return f[l][r];
    int tmp=1<<30;
    if(a[l]==a[r])
        tmp=min(dfs(l+1,r),dfs(l,r-1));
    for(int k=l;k<r;k++)
        tmp=min(tmp,dfs(l,k)+dfs(k+1,r));
    return f[l][r]=tmp;
}
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    memset(f,-1,sizeof(f));
    printf("%d\n",dfs(1,n));
    return 0;
}