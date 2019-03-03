#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
ll dp[25][5];
int a[25];
ll dfs(int pos,int cnt,bool limit){
	if(pos==-1)
		return 1;
	if(!limit && dp[pos][cnt]!=-1)
		return dp[pos][cnt];
	int up=limit?a[pos]:9;
	ll ans=0;
	for(int i=0;i<=up;i++){
		if(i==0)
			ans+=dfs(pos-1,cnt,limit&&a[pos]==i);
		else if(cnt<3)
			ans+=dfs(pos-1,cnt+1,limit&&a[pos]==i);
	}
	if(!limit)
		dp[pos][cnt]=ans;
	return ans;
}
ll solve(ll n){
	int len=0;
	while(n){
		a[len++]=n%10; n/=10;
	}
	return dfs(len-1,0,1);
}
int main(){
	memset(dp,-1,sizeof(dp));
	ll DC,l,r;
	cin>>DC;
	while(DC--){
		cin>>l>>r;
		cout<<solve(r)-solve(l-1)<<endl;
	}
	return 0;
}
