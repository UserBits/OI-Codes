#pragma G++ optimize(O2)
#include <cstdio>
#include <cstring>
typedef long long ll;
ll a[3][3],res[3][3],tmp[3][3];
int i,j,k,t,n;
const int mod=1000000007;
inline void qr(int &s){
	register char c=getchar();
	s=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		s=(s<<1)+(s<<3)+c-'0';
}
inline void qw(int s){
	if(s>9)
		qw(s/10);
	putchar(s%10+48);
}
void multi(ll a[3][3],ll b[3][3]){
	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			for(k=0;k<3;++k)
				tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j])%mod;
		}
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			a[i][j]=tmp[i][j];
			tmp[i][j]=0;
		}
	}
}
void power(int x){
	memset(a,0,sizeof(a));
	memset(res,0,sizeof(res));
	res[0][0]=res[0][1]=res[0][2]=1;
	a[1][0]=a[2][1]=a[0][2]=a[2][2]=1;
	while(x){
		if(x&1)
			multi(res,a);
		multi(a,a);
		x>>=1;
	}
	qw(res[0][2]);
	putchar('\n');
}
int main(){
    //freopen("testdata.in","r",stdin);
    //freopen("testdata.out","w",stdout);
	qr(t);
	while(t--){
		qr(n);
		if(n<=3){
			puts("1");
			continue;
		}
		power(n-3);
	}
}