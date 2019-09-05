#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename qRead>
inline void qr(qRead &s){
    char c=gc();
    s=0;
    qRead f=1;
    for(;c<'0'||c>'9';c=gc()){
        if(c=='-')
            f=-1;
    }
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
    s*=f;
}
inline void readc(char &c){
	c=gc();
	for(;c<'A'||c>'Z';c=gc());
}

typedef long long ll;
struct node{
	int key,cnt;
}a[1000005];
struct ask{
	int x;
	char op;
}q[1000005];
int s[1000005];
bool del[1000005];
ll ans[1000005];
const ll mod=317847191;

ll ksm(ll x,ll y){
	ll r=1;
	while(y){
		if(y&1)
			r=r*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return r;
}

int get(int val,int len){
	int l=1,r=len,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid].key==val)
			return mid;
		if(a[mid].key>val)
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int main(){
	int n,m;
	qr(n); qr(m);
	for(int i=1;i<=n;i++)
		qr(s[i]);
	sort(s+1,s+1+n);
	int now=s[1],tot=1,len=0;
	for(int i=2;i<=n;i++){
		if(s[i]==now)
			tot++;
		else{
			a[++len].cnt=tot;
			a[len].key=now;
			now=s[i];
			tot=1;
		}
	}
	a[++len].cnt=tot;
	a[len].key=now;
	for(int i=1;i<=m;i++){
		readc(q[i].op);
		if(q[i].op=='D'){
			qr(q[i].x);
			del[get(q[i].x,len)]=1;
		}
	}
	ll mn=1ll<<60,mx=-(1ll<<60),mul=1;
	for(int i=1;i<=len;i++){
		if(!del[i]){
			if(a[i].key<mn)
				mn=a[i].key;
			if(a[i].key>mx)
				mx=a[i].key;
			mul=mul*ksm(a[i].key,a[i].cnt)%mod;
		}
	}
	for(int i=m;i>0;i--){
		if(q[i].op=='D'){
			int k=q[i].x;
			int h=get(k,len);
			if(k<mn)
				mn=k;
			if(k>mx)
				mx=k;
			mul=mul*ksm(k,a[h].cnt)%mod;
		}
		else if(q[i].op=='B'){
			ans[i]=mx;
		}
		else if(q[i].op=='S'){
			ans[i]=mn;
		}
		else if(q[i].op=='M'){
			ans[i]=ksm(mx,mn)%mod;
		}
		else if(q[i].op=='T'){
			ans[i]=mul;
		}
	}
	for(int i=1;i<=m;i++){
		if(q[i].op!='D')
			printf("%lld\n",ans[i]);
	}
	return 0;
}
