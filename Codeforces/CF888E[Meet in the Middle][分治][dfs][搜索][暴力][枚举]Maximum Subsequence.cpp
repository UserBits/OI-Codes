#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n,n1,n2,x1,x2,a1[20],a2[20],m,r1[300000],r2[300000];
void dfs1(int dep,int sum){
    if(dep>n1){
        r1[++x1]=sum;
        return;
    }
    dfs1(dep+1,sum);
    dfs1(dep+1,(sum+a1[dep])%m);
}
void dfs2(int dep,int sum){
    if(dep>n2){
        r2[++x2]=sum;
        return;
    }
    dfs2(dep+1,sum);
    dfs2(dep+1,(sum+a2[dep])%m);
}
int main(){
    scanf("%d%d",&n,&m);
    n1=n>>1;
    n2=n-n1;
    for(int i=1;i<=n1;i++)
        scanf("%d",&a1[i]);
    for(int i=1;i<=n2;i++)
        scanf("%d",&a2[i]);
    if(n==1){
        printf("%d\n",a2[1]%m);
        return 0;
    }
    dfs1(1,0); dfs2(1,0);
    sort(r1+1,r1+1+x1);
    sort(r2+1,r2+1+x2);
    int i=1,j=x2,ans=0;
    while(i<=x1){
        while(r1[i]+r2[j]>=m && j>0)
            j--;
        if(!j) break;
        ans=max(r1[i]+r2[j],ans);
        i++;
    }
    ans=max(r1[x1]+r2[x2]-m,ans);
    printf("%d\n",ans);
    return 0;
}