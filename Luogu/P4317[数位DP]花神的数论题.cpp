#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll dp[51][51][51];
int a[51];
const int m=10000007;

inline ll qPow(ll x,ll y){
    ll r=1;
    while(y){
        if(y&1) r=r*x%m;
        x=x*x%m; y>>=1;
    }
    return r;
}

ll dfs(int pos,int cnt,int num,bool limit){
    if(pos==-1)
        return cnt==num;
    if(!limit && dp[pos][num][cnt]!=-1)
        return dp[pos][num][cnt];
    int up=limit?a[pos]:1; ll ans=0;
    for(int i=0;i<=up;++i)
        ans+=dfs(pos-1,cnt+(i==1),num,limit&&(i==a[pos]));
	if(!limit)
    	dp[pos][num][cnt]=ans;
    return ans;
}

ll solve(ll n){
    int len=0;
    while(n){
        a[len++]=n&1; n>>=1;
    }
    ll ans=1;
    for(int i=1;i<=len;++i){
        memset(dp,-1,sizeof(dp));
        ans=ans*qPow(i,dfs(len-1,0,i,1))%m;
    }
    return ans;
}

int main(){
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",solve(n));
    return 0;
}
