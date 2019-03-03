//#pragma G++ optimize(O3)
#define EOL putchar('\n')
#include <cstdio>
int f[1005];
inline int Find(int x){
	while(x!=f[x])
		x=f[x];
	return x;
}
inline int Union(int x,int y){
	register int tx=Find(x),ty=Find(y);
	if(tx!=ty)
		f[ty]=tx;
}
inline void qr(int &s){
	s=0;
	register char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		s=(s<<1)+(s<<3)+c-'0';
}
inline void qw(int s){
	if(s>9)
		qw(s/10);
	putchar(s%10+'0');
}
int main(){
	//freopen("test.out","w",stdout);
	register int n,m,x,y,ans;
	while(~scanf("%d",&n)){
		if(!n)
			break;
		qr(m);
		for(register int i=1;i<=n;i++)
			f[i]=i;
		while(m--){
			qr(x); qr(y);
			Union(x,y);
		}
		ans=-1;
		for(register int i=1;i<=n;i++)
			ans+=(f[i]==i);
		qw(ans);
		EOL;
	}
	return 0;
}
