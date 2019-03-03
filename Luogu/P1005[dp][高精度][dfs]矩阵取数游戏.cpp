#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct BigNum{
	int len,a[20];
	BigNum(){
		len=1;
		memset(a,0,sizeof(a));
	}
}dp[85][85],v[85][85],p[85];
BigNum mx(BigNum x,BigNum y){
	if(x.len!=y.len)
		return x.len>y.len?x:y;
	bool flag=0;
	for(int i=x.len;i;i--){
		if(x.a[i]>y.a[i])
			flag=1;
		if(!flag && x.a[i]<y.a[i])
			return y;
	}
	return x;
}
BigNum add(BigNum x,BigNum y){
	int ln=max(x.len,y.len)+1,up=0;
	BigNum ans;
	for(int i=1;i<=ln;i++){
		ans.a[i]=x.a[i]+y.a[i]+up;
		up=ans.a[i]/10000;
		ans.a[i]%=10000;
	}
	while(ans.a[ln]==0 && ln>1)
		ln--;
	ans.len=ln;
	return ans;
}
BigNum multi(BigNum x,BigNum y){
	BigNum ans;
	int ln=max(x.len,y.len)+5;
	for(int i=1;i<=x.len;i++){
		for(int j=1;j<=y.len;j++)
			ans.a[i+j-1]+=x.a[i]*y.a[j];
	}
	for(int i=1;i<=ln;i++){
		ans.a[i+1]+=ans.a[i]/10000;
		ans.a[i]%=10000;
	}
	while(ans.a[ln]==0 && ln)
		ln--;
	ans.len=ln;
	return ans;
}
BigNum getv(int x){
	BigNum ans;
	int ln=0;
	while(x){
		ans.a[++ln]=x%10000;
		x/=10000;
	}
	ans.len=ln;
	return ans;
}
int n,m;
BigNum dfs(int left,int right,int line){
	if(dp[left][right].a[1]!=-1){
		return dp[left][right];
	}
	if(left>right){
		BigNum tp;
		return dp[left][right]=tp;
	}
	BigNum ans;
	ans=mx(ans,add(multi(v[line][left],p[left+m-right]),dfs(left+1,right,line)));
	ans=mx(ans,add(multi(v[line][right],p[left+m-right]),dfs(left,right-1,line)));
	return dp[left][right]=ans;
}
int main(){
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			v[i][j]=getv(x);
		}
	}
	p[1].a[1]=2;
	BigNum tmp;
	tmp.a[1]=2;
	for(int i=2;i<=80;i++)
		p[i]=multi(p[i-1],tmp);
	BigNum ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++)
				dp[j][k].a[1]=-1;
		}
		ans=add(ans,dfs(1,m,i));
	}
	printf("%d",ans.a[ans.len]);
	for(int i=ans.len-1;i>0;i--)
        printf("%04d",ans.a[i]);
    return 0;
}
