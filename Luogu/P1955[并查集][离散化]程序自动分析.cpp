#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename qRead>
inline void qr(qRead &s){
	char c=gc();
	s=0;
	for(;c<'0'||c>'9';c=gc());
	for(;c>='0'&&c<='9';c=gc())
		s=(s<<1)+(s<<3)+(c-'0');
}

const int N=100001;
int f[N],p[N<<1];
struct node{
	int x,y;
	bool flag;
	friend bool operator < (node p,node q){
		return p.flag>q.flag;
	}
}a[N];

int get(int x){
	if(x==f[x])
		return x;
	return f[x]=get(f[x]);
}
void merge(int x,int y){
	x=get(x);
	y=get(y);
	f[x]=y;
}

int main(){
	//freopen("testdata.in","r",stdin);
	int t;
	qr(t);
	while(t--){
		int n=0,m;
		memset(p,0,sizeof(p));
		qr(m);
		for(int i=1;i<=m;i++){
			qr(a[i].x); qr(a[i].y); qr(a[i].flag);
			p[++n]=a[i].x;
			p[++n]=a[i].y;
		}
		sort(p+1,p+1+n);
		n=unique(p+1,p+1+n)-p-1;
		sort(a+1,a+1+m);
		for(int i=1;i<=m;i++){
			a[i].x=lower_bound(p+1,p+1+n,a[i].x)-p;
			a[i].y=lower_bound(p+1,p+1+n,a[i].y)-p;
		}
		for(int i=1;i<=n;i++)
			f[i]=i;
		bool get_ans=0;
		for(int i=1;i<=m;i++){
			if(a[i].flag)
				merge(a[i].x,a[i].y);
			else if(get(a[i].x)==get(a[i].y)){
				get_ans=1;
				puts("NO");
				break;
			}
		}
		if(!get_ans)
			puts("YES");
	}
	return 0;
}
