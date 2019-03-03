#include<iostream>
#include<string>
using namespace std;
struct stack
{
	int t;
	string s;
}st[25];
int x;
string s;
int main()
{
	cin>>s;
	int lens=s.size(),len=0;
	for (int i=0; i<lens; i++)
	{
		if (s[i]<='Z' && s[i]>='A')
			st[len].s+=s[i];
		else if (s[i]=='[')
		{
			st[++len].s="";
			st[len].t=0;
		}
		else if (s[i]<='9' && s[i]>='0')
			st[len].t=st[len].t*10+(s[i]-'0');
		else if (s[i]==']')
		{
			for (int j=1; j<=st[len].t; j++)
				st[len-1].s+=st[len].s;
			len--;
		}
	}
	cout<<st[0].s<<endl;
	return 0;
}

