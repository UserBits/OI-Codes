#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=100005;
typedef long long ll;
int belong[N],l[N],r[N],n,block,num;
ll add[N],v[N],sum[N];

template<typename r_e_a_d>
inline void qr(r_e_a_d &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}

inline void update(int a,int b,ll c){
	int x=min(r[belong[a]],b);
	for(int i=a;i<=x;i++){
		v[i]+=c;
		sum[belong[a]]+=c;
	}
	if(belong[a]!=belong[b]){
		for(int i=l[belong[b]];i<=b;i++){
			v[i]+=c;
			sum[belong[b]]+=c;
		}
	}
	x=belong[b];
	for(int i=belong[a]+1;i<x;i++){
		add[i]+=c;
 		sum[i]+=c*(r[i]-l[i]+1);
 	}
}

inline ll query(int a,int b){
	int x=min(r[belong[a]],b);
	ll ans=0;
	for(int i=a;i<=x;i++)
		ans+=v[i]+add[belong[a]];
	if(belong[a]!=belong[b]){
		for(int i=l[belong[b]];i<=b;i++)
			ans+=v[i]+add[belong[b]];
	}
	x=belong[b];
	for(int i=belong[a]+1;i<x;i++)
		ans+=sum[i];
	return ans;
}

inline void wr(ll x){
	if(x>9)
		wr(x/10);
	putchar(x%10+48);
}

int main(){
	int m;
	qr(n); qr(m);
	for(int i=1;i<=n;i++)
		qr(v[i]);
    block=(int)sqrt(n*1.0);
    num=n/block;
    if(n%block)
        num++;
    for(int i=1;i<=n;i++)
        belong[i]=(i-1)/block+1;
    for(int i=1;i<=num;i++){
        l[i]=(i-1)*block+1;
        r[i]=i*block;
        for(int j=l[i];j<=r[i];j++)
			sum[i]+=v[j];
    }
	r[num]=n;
	int opt,x,y;
	ll z;
	while(m--){
		qr(opt);
		if(opt==1){
			qr(x); qr(y); qr(z);
			update(x,y,z);
		}
		else{
			qr(x); qr(y);
			wr(query(x,y));
			putchar('\n');
		}
	}
	return 0;
}
