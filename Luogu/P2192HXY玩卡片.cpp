#include<iostream>
using namespace std;
int main()
{
	int n,five=0,zero=0,p;
	cin>>n;
	while(n--)
	{
		cin>>p;
		if(p==0)
			zero++;
		else
			five++;
	}
	if(zero==0)
	{
		cout<<-1;
		return 0;
	}
	if(five<9)
	{
		cout<<0;
		return 0;
	}
	five=five-(five%9);
	while(five--)
		cout<<5;
	while(zero--)
		cout<<0;
	return 0;
}
