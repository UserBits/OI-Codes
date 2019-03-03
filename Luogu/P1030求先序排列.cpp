#include<iostream>
#include<string>
using namespace std;
void dfs(string m,string l)
{
	int len=m.length();
	if (len<=1)
	{
		cout<<m;
		return;
	}
	int u=m.find(l[len-1]);
	cout<<m[u];
	dfs(m.substr(0,u),l.substr(0,u));
	dfs(m.substr(u+1,len-u-1),l.substr(u,len-1-u));
}
int main()
{
	string m,l;
	cin>>m>>l;
	dfs(m,l);
	return 0;
}

