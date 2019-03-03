#include <iostream>
#include <string>
using namespace std;
string s;
string check(int left,int right)
{
	int zero=0,one=0;
	for(int i=left; i<=right; i++)
	{
		if(s[i]=='0')
			zero++;
		else
			one++;
	}
	if(one==0)
		return "B";
	if(zero==0)
		return "I";
	else
		return "F";
}
string work(int left,int right)
{
	if(left>=right)
		return check(left,right);
	int mid=(left+right)/2;
	return work(left,mid)+work(mid+1,right)+check(left,right);
}
int main()
{
	int d;
	cin>>d>>s;
	cout<<work(0,s.size()-1)<<endl;
	return 0;
}
