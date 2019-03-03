#include <iostream>
#include <cstring>
#define ref(i,x,y)for(int i=x;i<=y;i++)
using namespace std;
int m,l,n,f[201][51][2];
bool b[201];
int main()
{
	cin>>m>>l>>n;
	ref(i,1,n)
	{
		int tmp;
		cin>>tmp;
		b[tmp]=1;
	}
	memset(f,1,sizeof f);
	ref(i,0,l)if(!b[i])f[i][0][0]=0;
	else break;
	ref(i,1,l)
	ref(j,1,min(i,m))
	{
		f[i][j][1]=min(f[i-1][j][1],f[i-1][j-1][0])+1;
		if(!b[i])f[i][j][0]=min(f[i-1][j][1],f[i-1][j][0]);
	}
	int ans=1e8;
	ref(i,1,m)
	ans=min(ans,min(f[l][i][0],f[l][i][1]));
	/*
	ref(i,1,l)
	 ref(j,1,min(i,m))
	  cout<<i<<" "<<j<<"  :  "<<min(f[i][j][0],f[i][j][1])<<endl;
	*/
	cout<<ans;
}
