#include<iostream>
#include<algorithm>
using namespace std;
int num[60];
int main()
{
	int n;
	long long ans=1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)
	{
		ans*=num[i]-i+1;
		ans%=1000000007;
	}
	cout<<ans<<endl;
	return 0;
}
