#include <iostream>
using namespace std;
double a,s=10.0;
int n,m=0,t=0,o=1,b;
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a>>b;
		s-=a;
		if(s>10.0)
			s=10.0;
		if(s<=0.0)
			break;
		t+=b;
	}
	while(t-o>=0)
	{
		t-=o;
		m++;
		o*=2;
	}
	cout<<m<<' '<<t;
	return 0;
}

