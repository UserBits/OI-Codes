#include <cstdio>
template<typename qPow>
qPow q_pow(qPow x,qPow y,qPow mod){
	qPow res=1;
	while(y){
		if(y&1)
			res=res*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return res;
}
char ReadChar(){
	char c=getchar();
	while(c=='\t'||c=='\n'||c==' '||c=='\r')
		c=getchar();
	return c;
}
template<typename GcdLcm>
GcdLcm gcd(GcdLcm x,GcdLcm y){
	return y==0?x:gcd(y,x%y);
}
template<typename GcdLcm>
GcdLcm lcm(GcdLcm x,GcdLcm y){
	return x/gcd(x,y)*y;
}
