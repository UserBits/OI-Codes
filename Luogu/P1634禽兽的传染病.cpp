#include<iostream>
using namespace std;
int main()
{
	unsigned long long s=1,n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		s*=n+1;
	cout<<s<<endl;
	return 0;
}
