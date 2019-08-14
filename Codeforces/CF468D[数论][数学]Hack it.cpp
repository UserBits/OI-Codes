#include <cstdio>

typedef long long ll;
ll Inf=1e18;
ll l,r,a;

int main(){
	scanf("%lld",&a);
	l=a-Inf%a*9%a*9%a;
	r=l+Inf-1;
	printf("%lld %lld\n",l,r);
	return 0;
}


