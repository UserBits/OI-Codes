#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N=1005;
struct node{
    int id,dep;
    friend bool operator < (node x, node y){
        return x.dep>y.dep;
    }
}a[N];
int fa[N],dis[N];
int main(){
    int n;
    scanf("%d",&n);
    fa[1]=1; a[1].id=1;
    memset(dis,0x3f,sizeof(dis));
    for(int i=2;i<=n;i++){
        a[i].id=i;
        scanf("%d",&fa[i]);
        a[i].dep=a[fa[i]].dep+1;
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++){
        int cur=a[i].id,father=fa[cur],grand=fa[father];
        dis[cur]=min(dis[cur],min(dis[father]+1,dis[grand]+2));
        if(dis[cur]>2){
            ans++;
            dis[grand]=0;
            cur=grand; father=fa[cur]; grand=fa[father];
            dis[father]=min(dis[father],1);
            dis[grand]=min(dis[grand],2);
        }
    }
    printf("%d\n",ans);
    //system("pause");
}