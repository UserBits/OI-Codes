#include <iostream>
#include <cmath>
using namespace std;
bool p[10005]= {1,1};
int main()
{
	int n,k;
	cin>>n>>k;
	if(n<k+2)
	{
		cout<<"empty\n";
		return 0;
	}
	bool flag=0;
	int t=sqrt(n);
	for(int i=2; i<=t; i++)
	{
		if(p[i])
			continue;
		for(int j=i+i; j<=n; j+=i)
			p[j]=1;
	}
	if(!p[2] && !p[2+k])
	{
		cout<<2<<' '<<2+k<<endl;
		flag=1;
	}
	for(int i=3; i+k<=n; i+=2)
	{
		if(p[i] || p[i+k]) continue;
		cout<<i<<' '<<i+k<<endl;
		flag=1;
	}
	if(!flag)
		cout<<"empty\n";
	return 0;
}
