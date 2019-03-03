#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
	int n;
	bool p=0;
	cin>>n>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]!='0')
		{
			if(p==1)
				cout<<'+';
			cout<<s[i]<<'*'<<n<<'^'<<len-i-1;
			p=1;
		}
	}
	return 0;
}
