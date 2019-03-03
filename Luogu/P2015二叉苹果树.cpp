#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,q,f[105][105],apple[105];
struct node
{
    int father[3],cnt;
}a[105];
inline void dfs(int dep,int res)
{
    if(res==0)
        f[dep][res]=0;
    else if(a[dep].cnt==0)
        f[dep][res]=apple[dep];
    else 
    {
        for(int i=0;i<res;i++)
        {
            if(f[a[dep].father[1]][i]==0)
                dfs(a[dep].father[1],i);
            if(f[a[dep].father[2]][res-i-1]==0)
                dfs(a[dep].father[2],res-i-1);
            f[dep][res]=max(f[dep][res],
            f[a[dep].father[1]][i]+f[a[dep].father[2]][res-i-1]+apple[dep]);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    int x,y,z;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        a[x].father[++a[x].cnt]=y;
        apple[y]=z;
    }
    dfs(1,q+1);
    printf("%d\n",f[1][q+1]);
    system("pause");
    return 0;
}