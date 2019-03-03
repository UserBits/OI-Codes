#include <cstdio>
int a[10005],n,m,ans,x,y;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        a[x]++;
        a[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)
              ans++;
    }
    if(ans)
       printf("%d\n",ans>>1);
    else
       printf("%d\n",ans+1);
    return 0;
}
