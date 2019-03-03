#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long f[25][25][25];
long long dfs(long long a,long long b,long long c)
{
	if(a<=0 || b<=0 || c<=0)
		return 1;
	if(a>20 || b>20 || c>20)
		return dfs(20,20,20);
	if(a<b && b<c)
	{
		if(f[a][b][c]==-1)
			f[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
	}
	else if(f[a][b][c]==-1)
		f[a][b][c]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
	return f[a][b][c];
}
int main()
{
	memset(f,-1,sizeof(f));
	long long a,b,c;
	do
	{
		cin>>a>>b>>c;
		if(a!=-1 || b!=-1 || c!=-1)
			printf("w(%d, %d, %d) = %d\n",a,b,c,dfs(a,b,c));
	}
	while(a!=-1 || b!=-1 || c!=-1);
	return 0;
}
