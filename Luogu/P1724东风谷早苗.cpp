#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
	int x=0,y=0,t,l,a=0,m,n;
	cin>>s;
	l=s.size();
	cin>>t;
	n=t/l;
	m=t%l;
	for(int i=0; i<l; i++)
	{
		if(s[i]=='N')
			y++;
		if(s[i]=='S')
			y--;
		if(s[i]=='E')
			x++;
		if(s[i]=='W')
			x--;
	}
	x=x*n;
	y=y*n;
	for(int i=0; i<m; i++)
	{
		if(s[i]=='N')
			y++;
		if(s[i]=='S')
			y--;
		if(s[i]=='E')
			x++;
		if(s[i]=='W')
			x--;
	}
	cout<<x<<' '<<y;
	return 0;
}
