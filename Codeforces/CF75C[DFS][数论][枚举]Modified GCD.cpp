#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int f[101],g[101],len=0;
set<int> s;
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
inline void dfs(int dep,int sum){
    if(dep>len){
        s.insert(sum);
        return;
    }
    dfs(dep+1,sum);
    int t=f[dep];
    for(int i=1;i<=g[dep];i++){
        dfs(dep+1,sum*t);
        t*=f[dep];
    }
}
int main(){
    int a,b,q,l,r;
    scanf("%d%d",&a,&b);
    int tmp=gcd(a,b);
    s.insert(tmp);
    for(int i=2;i*i<=tmp;i++){
        if(tmp%i==0){
            f[++len]=i;
            while(tmp%i==0){
                tmp/=i;
                g[len]++;
            }
        }
    }
    if(tmp>1){
        len++;
        f[len]=tmp;
        g[len]=1;
    }
    dfs(1,1);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        set<int>:: iterator it;
        it=s.upper_bound(r);
        if(it==s.begin()){
            puts("-1");
            continue;
        }
        it--;
        if((*it)>=l)
            printf("%d\n",(*it));
        else
            puts("-1");
    }
    return 0;
}

