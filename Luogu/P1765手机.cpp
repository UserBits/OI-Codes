#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int a[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
string s;
int main()
{
	int sum=0,i=0;
	getline(cin,s);
	for(i=0;i<s.size();i++)
	{
		if(s[i]==32)
			sum++;
		if(s[i]>='a' && s[i]<='z')
			sum+=a[s[i]-'a'];
	}
	cout<<sum<<endl;
	return 0;
}

