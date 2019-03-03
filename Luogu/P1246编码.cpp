// luogu-judger-enable-o2
#include <string>
#include <iostream>
#include <map>
using namespace std;
int cnt;
map<string,int> p;
string now;
inline void dfs(int len,int dep)
{
	if(dep>len)
	{
		cnt++;
		p[now]=cnt;
		return;
	}
	for(char i=(dep==1?'a':now[dep-2]+1);i<='z';i++)
	{
		now[dep-1]=i;
		dfs(len,dep+1);
	}
}
int main()
{
	for(int i=1;i<=6;i++)
	{
		now.clear();
		now.resize(i);
		dfs(i,1);
	}
	cin>>now;
	cout<<p[now]<<endl;
	return 0;
}
