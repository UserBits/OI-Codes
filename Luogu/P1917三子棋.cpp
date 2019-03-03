#include <iostream>
using namespace std;
char a[15];
int main()
{
	int s=0;
	bool p=0;
	for (int i=1; i<=9; i++)
	{
		cin>>a[i];
		if (a[i]!='-')
			s++;
		if (a[i]=='X' && (i==2 || i==4 || i==6 || i==8))
			p=1;
	}
	if (p)
		cout<<"xiaoa will win."<<endl;
	else
		cout<<"Dont know."<<endl;
	cout<<s<<endl;
	return 0;
}
