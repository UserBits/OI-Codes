#pragma G++ optimize(O3)
// Warning!!!!!!!!
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll a[100005],b[100005];
bool used[100005];
template<typename qReadTp>
inline void qr(qReadTp &s){
	s=0;
	register char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		s=(s<<1)+(s<<3)+c-'0';
}
template<typename FunCheckTp>
FunCheckTp ChkPrm(FunCheckTp n){
	for(FunCheckTp i=2;i*i<=n;i++){
		if(n%i==0)
			return 2;
	}
	return 1;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int t,n,m;
	qr(t);
	while(t--){
		qr(n);
		qr(m);
		memset(used,0,sizeof(used));
		for(int i=1;i<=n;i++)
			qr(a[i]);
		for(int i=1;i<=m;i++)
			qr(b[i]);
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+m,cmp);
		int x,y;
		for(x=y=1;x<=m;x++){
			while(b[x]<a[y])
				y++;
			used[y]=1;
			y++;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!used[i]&&a[i]!=1){
				cnt+=ChkPrm(a[i]);
				if(cnt>1)
					break;
			}
		}
		if(cnt==1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

