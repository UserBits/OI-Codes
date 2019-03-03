#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename qReadTp>
inline void qr(qReadTp &s){
	s=0;
	char c=getchar();
	int flag=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-')
			flag=-1;
	}
	for(;c>='0'&&c<='9';c=getchar())
		s=(s<<1)+(s<<3)+c-'0';
	s*=flag;
}
const int N=1000005;
ll a[N],x[N],y[N];
int main()
{
	int n;
	qr(n);
	for(int i=1;i<=n;i++){
		qr(a[i]);
		if(x[i-1]>=0)
			x[i]=x[i-1]+a[i];
		else
			x[i]=a[i];
	}
	for(int i=n;i>=1;i--){
		if(y[i+1]>=0)
			y[i]=y[i+1]+a[i];
		else
			y[i]=a[i];
	}
	for(int i=2;i<=n;i++){
		if(x[i-1]>x[i])
			x[i]=x[i-1];
	}
	for(int i=n-1;i>=1;i--){
		if(y[i+1]>y[i])
			y[i]=y[i+1];
	}
	ll ans=-1e17;
	for(int i=2;i<n;i++)
		ans=max(ans,x[i-1]+y[i+1]);
	cout<<ans<<endl;
    return 0;
}
