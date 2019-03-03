#include<iostream>
#include<string>
using namespace std;
int ans[3];
string s;
int main()
{
	cin>>s;
	int len=s.length()-1;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='=')
		{
			if(s[i+1]>='0' && s[i+1]<='9')
				ans[s[i-2]-97]=s[i+1]-48;
			else
				ans[s[i-2]-97]=ans[s[i+1]-97];
		}
	}
	cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl;
	return 0;
}

