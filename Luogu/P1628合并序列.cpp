#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[100005],ptr;
int len;
bool cmp(string x,string y)
{
	return x<y?1:0;
}
bool member(string k)
{
	for(int i=0;i<len;i++)
	{
		if(k[i]!=ptr[i])
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	cin>>ptr;
	len=ptr.length();
	for(int i=0;i<n;i++)
	{
		if(member(s[i])==1)
			cout<<s[i]<<endl;
	}
	return 0;
}
