#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int f[305][305],val[305],BrotherNode[305],FatherNode[305];
void dfs(int p,int q)
{
	if(f[p][q]>=0)
		return;
	if(p==0||q==0)
	{
		f[p][q]=0;
		return;
	}
	dfs(BrotherNode[p],q);
	f[p][q]=max(f[p][q],f[BrotherNode[p]][q]);
	for(int i=0;i<q;i++)
	{
		dfs(FatherNode[p],q-i-1);
		dfs(BrotherNode[p],i);
		f[p][q]=max(f[p][q],f[BrotherNode[p]][i]+f[FatherNode[p]][q-i-1]+val[p]);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int tp;
		cin>>tp>>val[i];
		if(tp==0)
			tp=n+1;
		BrotherNode[i]=FatherNode[tp];
		FatherNode[tp]=i;
	}
	memset(f,-1,sizeof(f));
	dfs(FatherNode[n+1],m);
	printf("%d\n",f[FatherNode[n+1]][m]);
	//system("pause");
	return 0;
}