#include<iostream>
using namespace std;
int main()
{
	long long b,p,k;
	cin>>b>>p>>k;
	cout<<b<<'^'<<p<<" mod "<<k<<'=';
	long long result=1;
	while(p>0)
	{
		if(p%2==1)
			result=result*b%k;
		p/=2;
		b=b*b%k;
	}
	cout<<result<<endl;
	return 0;
}
