#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
int p[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47},a[20];
double ans=1e18;

double QuickPower(double x,int y){
	double Res=1;
	while(y){
		if(y&1)
			Res*=x;
		x*=x;
		y>>=1;
	}
	return Res;
}

void dfs(int dep,int rest){
	if(rest==1){
		double sum=1;
		for(int i=1;i<dep;i++)
			sum*=QuickPower(p[i],a[i]-1);
		if(sum<=1e18 && sum<ans)
			ans=sum;
		return;
	}
	for(int i=rest;i>1;i--){
		if(rest%i==0){
			a[dep]=i;
			dfs(dep+1,rest/i);
		}
	}
}

int main(){
	int n;
	cin>>n;
	dfs(1,n);
	cout<<(ll)ans<<endl;
	return 0;
}
