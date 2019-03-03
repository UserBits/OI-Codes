#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n,m,a,b,ans;
	while(cin>>n>>m>>a>>b)
    {
    	a=min(a,n);
    	b=min(b,m);
    	if(a==0)
			ans=b;
		else if(b==0)
			ans=a;
		else if((n+1)*b<m)
			ans=n+(n+1)*b;
		else if((m+1)*a<n)
			ans=m+(m+1)*a;
		else
			ans=n+m;
		cout<<ans<<endl;
    }
    return 0;
}