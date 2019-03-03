#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
const int N=300005;
int Dis[N];
bool Inq[N];
vector<int> l;
inline int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    int n,m,x,t;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        t=min(m,x-1);
        for(int j=0;j<=t;j++)
            l.push_back(x-j);
    }
    sort(l.begin(),l.end());
    n=unique(l.begin(),l.end())-l.begin();
    if(l[0]==1){
        puts("-1");
        return 0;
    }
    t=l[0];
    for(int i=1;i<n;i++)
        t=gcd(t,l[i]);
    if(t>1){
        puts("-1");
        return 0;
    }
    queue<int> q;
    for(int i=1;i<l[0];i++)
        Dis[i]=1e9;
    Inq[0]=1;
    q.push(0);
    int u,v;
    while(!q.empty()){
        u=q.front();
        q.pop();
        Inq[u]=0;
        for(int i=1;i<n;i++){
            v=(u+l[i])%l[0];
            if(Dis[u]+l[i]<Dis[v]){
                Dis[v]=Dis[u]+l[i];
                if(!Inq[v]){
                    Inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<l[0];i++)
        ans=max(ans,Dis[i]-l[0]);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}