#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
string s;
map<string,bool>a;
int main()
{
	int m=0,n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		if(!a[s])
		{
			m++;
			a[s]=1;
		}
	}
	cout<<m;
	return 0;
}
