#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double a,s=0,h=2;
	int t=0;
	cin>>a;
	while(s<a)
	{
		s+=h;
		h*=0.98;
		t++;
	}
	cout<<t<<endl;
	return 0;
}
