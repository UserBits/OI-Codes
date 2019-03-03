#include<iostream>
using namespace std;
int n,m,ans=0;
void dfs(int l,int k,int r)
{
	int i;
	if(k==m)
	{
		ans++;
		return;
	}
	int s=r/(m-k+1);
	for(i=l;i<=s;i++)
		dfs(i,k+1,r-i);
}
int main()
{
	cin>>n>>m;
	ans=0;
	dfs(1,1,n);
	cout<<ans<<endl;
	return 0;
}

