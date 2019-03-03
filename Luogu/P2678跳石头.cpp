#include <cstdio>
using namespace std;
int a[50005],n,m,l;
bool check(int jump){
	int cnt=0,now=0;
	for(int i=0;i<=n;){
		i++;
		if(a[i]-a[now]<jump)
			cnt++;
		else
			now=i;
	}
	return cnt<=m;
}
template<typename ReadType>
inline void qr(ReadType &s){
	s=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		s=(s<<1)+(s<<3)+(c-'0');
}
int main(){
	qr(l);
	qr(n);
	qr(m);
	for(int i=1;i<=n;i++)
		qr(a[i]);
	a[n+1]=l;
	int low=1,high=l,ans,mid;
	while(low<=high){
		mid=(low+high)>>1;
		if(check(mid)){
			ans=mid;
			low=mid+1;
		}
		else
			high=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
