#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s[25];
bool cmp(string x,string y)
{
	string xy=x+y,yx=y+x;
	return xy>yx;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
		cout<<s[i];
	return 0;
}

