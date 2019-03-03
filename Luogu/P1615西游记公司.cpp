#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	unsigned long long a,b,c,d,e,f,n;
	scanf("%lld:%lld:%lld\n%lld:%lld:%lld\n%lld",&a,&b,&c,&d,&e,&f,&n);
	unsigned long long ans=n*((f-c)+(e-b)*60+(d-a)*3600);
	cout<<ans<<endl;
	return 0;
}
