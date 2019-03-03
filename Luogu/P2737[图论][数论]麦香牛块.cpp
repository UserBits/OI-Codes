#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
vector<int> l;
ll Dis[300];
bool Inq[300];
int main(){
	//freopen("nuggets.in","r",stdin);
	//freopen("nuggets.out","w",stdout);
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x==1){
			puts("0");
			return 0;
		}
		l.push_back(x);
	}
	sort(l.begin(),l.end());
	n=unique(l.begin(),l.end())-l.begin();
	int d=l[0];
	for(int i=1;i<n;i++)
		d=gcd(d,l[i]);
	if(d>1){
		puts("0");
		return 0;
	}
	queue<int> q;
	q.push(0);
	Inq[0]=1;
	for(int i=0;i<l[0];i++)
		Dis[i]=2e9+1;
	Dis[0]=0;
	int r;
	while(!q.empty()){
		r=q.front();
		q.pop();
		Inq[r]=0;
		for(int i=1;i<n;i++){
			int v=(r+l[i])%l[0];
			if(Dis[r]+l[i]<Dis[v]){
				Dis[v]=Dis[r]+l[i];
				if(!Inq[v])
					q.push(v);
			}
		}
	}
	ll ans=0;
	for(int i=0;i<l[0];i++)
		ans=max(ans,Dis[i]-l[0]);
	cout<<ans<<endl;
	return 0;
}
