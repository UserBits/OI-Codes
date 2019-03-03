#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1000001;
int belong[N],l[N],r[N],add[N],n,block,v[N],num,t[N];
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
void reinit(int x){
	for(int i=l[belong[x]];i<=r[belong[x]];i++)
		t[i]=v[i];
	sort(t+l[belong[x]],t+r[belong[x]]+1);
}
void update(int a,int b,int c){
	int x=min(r[belong[a]],b);
	for(int i=a;i<=x;i++)
		v[i]+=c;
	reinit(a);
	if(belong[a]!=belong[b]){
		for(int i=l[belong[b]];i<=b;i++)
			v[i]+=c;
		reinit(b);
	}
	x=belong[b];
	for(int i=belong[a]+1;i<x;i++)
		add[i]+=c;
}
int query(int a,int b,int c){
	int ans=0;
	int x=min(r[belong[a]],b);
	for(int i=a;i<=x;i++){
		if(v[i]+add[belong[a]]>=c)
			ans++;
	}
	if(belong[a]!=belong[b]){
		for(int i=l[belong[b]];i<=b;i++){
			if(v[i]+add[belong[b]]>=c)
				ans++;
		}
	}
	x=belong[b];
	for(int i=belong[a]+1;i<x;i++)
		ans+=r[i]-(lower_bound(t+l[i],t+r[i]+1,c-add[i])-t)+1;
	return ans;
}
inline void gc(char &c){
	c=getchar();
	while(c!='A' && c!='M')
		c=getchar();
}
inline void wr(int s){
	if(s>9)
		wr(s/10);
	putchar(s%10+'0');
}
int main(){
	int q;
	qr(n); qr(q);
	for(int i=1;i<=n;i++)
		qr(v[i]);
    block=(int)sqrt(n*1.0);
    num=n/block;
    if(n%block)
        num++;
    for(int i=1;i<=n;i++){
        belong[i]=(i-1)/block+1;
        t[i]=v[i];
    }
    for(int i=1;i<=num;i++){
        l[i]=(i-1)*block+1;
        r[i]=i*block;
    }
	r[num]=n;
	for(int i=1;i<=num;i++)
		sort(t+l[i],t+r[i]+1);
	char opt;
	int x,y,z;
	while(q--){
		gc(opt);
		qr(x); qr(y); qr(z);
		if(opt=='M')
			update(x,y,z);
		else{
			wr(query(x,y,z));
			putchar('\n');
		}
	}
	return 0;
}
