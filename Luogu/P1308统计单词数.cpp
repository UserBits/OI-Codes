#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string a,b;
int main()
{
	int x=-1,y=0;
	getline(cin,a);
	getline(cin,b);
	int la=a.length(),lb=b.length();
	int i=0;
	while(i<lb)
	{
		while(b[i]==' ' && i<lb)
			i++;
		int j=0;
		while(j<la && i<lb)
		{
			if(a[j]==b[i] || abs(a[j]-b[i])==32)
				i++,j++;
			else
				break;
		}
		if(j==la && (b[i]==' ' || i==lb-1))
		{
			if(x==-1)
				x=i-la;
			y++;
		}
		while(b[i]!=' ' && i<lb)
			i++;
	}
	if(x<0)
		cout<<x;
	else
		cout<<y<<' '<<x;
	return 0;
}

