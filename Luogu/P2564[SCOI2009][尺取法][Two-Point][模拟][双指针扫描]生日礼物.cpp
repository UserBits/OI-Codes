#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

inline void qr(int &s){
	s=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		s=(s<<1)+(s<<3)+(c-'0');
}

struct node{
	int col,pos;
}a[1000005];

bool cmp(node x,node y){
	return x.pos<y.pos;
}

int n,k,p[70];
inline bool check(){
	for(int i=1;i<=k;i++){
		if(!p[i])
			return 0;
	}
	return 1;
}

int main(){
	qr(n); qr(k);
	n=0;
	for(int i=1;i<=k;i++){
		int x,y;
		qr(x);
		while(x--){
			qr(y);
			a[++n].col=i;
			a[n].pos=y;
		}
	}
	sort(a+1,a+1+n,cmp);
	int l=1,r=1,ans=2e9;
	while(r<=n){
		while(!check() && r<=n){
			p[a[r].col]++;
			r++;
		}
		if(r>l && check())
			ans=min(ans,a[r-1].pos-a[l].pos);
		p[a[l].col]--;
		l++;
	}
	printf("%d\n",ans);
	return 0;
}