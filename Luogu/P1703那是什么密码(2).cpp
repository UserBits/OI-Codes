#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int size=5010;
int str[size];
int main()
{
	string s,k;
	cin>>k;
	for(int i=0; i<k.length(); i++)
	{
		for(int j=i; j<size; j+=k.length())
		{
			if(k[i]>='A' && k[i]<='Z')
				str[j]=(int)(k[i]-'A');
			else
				str[j]=(int)(k[i]-'a');
		}
	}
	cin>>s;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			if(s[i]+str[i]>'Z')
				s[i]=s[i]+str[i]-26;
			else
				s[i]=s[i]+str[i];
		}
		else
		{
			if(s[i]+str[i]>'z')
				s[i]=s[i]+str[i]-26;
			else
				s[i]=s[i]+str[i];
		}
	}
	int n,a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		string t1=s.substr(0,a-1);
		string t2=s.substr(a-1,b-a+1);
		string t3=s.substr(b,s.length()-b);
		reverse(t2.begin(),t2.end());
		s=t1+t2+t3;
	}
	cout<<s<<endl;
	return 0;
}
