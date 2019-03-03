#include <cstdio>
#include <cstdlib>
#include <cstring>

bool p[2005],f[25];
int a[25],n,m,ans;

void dp(){
    memset(p,0,sizeof(p));
    p[0]=1;
    int sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(f[i])
            continue;
        for(int j=sum;j>=0;j--){
            if(p[j] && !p[j+a[i]]){
                cnt++; p[j+a[i]]=1;
            }
        }
        sum+=a[i];
    }
    if(cnt>ans)
        ans=cnt;
}

void dfs(int x,int y){
    if(y>m)
        return;
    if(x>n){
        if(y==m)
            dp();
        return;
    }
    dfs(x+1,y);
    f[x]=1;
    dfs(x+1,y+1);
    f[x]=0;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}