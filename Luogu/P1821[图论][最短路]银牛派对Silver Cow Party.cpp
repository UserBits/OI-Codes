#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1001][1001],b[1001][1001],s[1001],t[1001];
bool p[1001];
int main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            a[i][j]=b[i][j]=1e9;
    }
    int u,v,l;
    while(m--){
        scanf("%d%d%d",&u,&v,&l);
        a[u][v]=min(a[u][v],l);
        b[v][u]=min(b[v][u],l);
    }
    p[x]=1;
	for(int i=1;i<=n;i++)
        s[i]=a[x][i];
	s[x]=0;
    for(int i=1;i<=n;i++){
        int tmp=0,maxn=1e9;
        for(int j=1;j<=n;j++){
            if(s[j]<maxn && !p[j]){
                maxn=s[j];
                tmp=j;
            }
        }
        if(tmp==0)
            break;
        p[tmp]=1;
        for(int j=1;j<=n;j++){
            if(s[tmp]+a[tmp][j]<s[j])
                s[j]=s[tmp]+a[tmp][j];
        }
    }
    memset(p,0,sizeof(p));
    p[x]=1;
	for(int i=1;i<=n;i++)
        t[i]=b[x][i];
	t[x]=0;
    for(int i=1;i<=n;i++){
        int tmp=0,maxn=1e9;
        for(int j=1;j<=n;j++){
            if(t[j]<maxn && !p[j]){
                maxn=t[j];
                tmp=j;
            }
        }
        if(tmp==0)
            break;
        p[tmp]=1;
        for(int j=1;j<=n;j++){
            if(t[tmp]+b[tmp][j]<t[j])
                t[j]=t[tmp]+b[tmp][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,s[i]+t[i]);
    printf("%d\n",ans);
    return 0;
}