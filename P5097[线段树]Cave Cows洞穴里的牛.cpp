#include <cstdio>
#include <algorithm>
#include <cstdlib>
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

const int N=25005;
int sum[4*N],add[4*N],a[N];

inline void PushUp(int Root){
	sum[Root]=min(sum[Root<<1],sum[Root<<1|1]);
}

void Build(int Root,int L,int R){ 
	if(L==R){
		sum[Root]=a[L];
		return;
	}
	int mid=L+R>>1;
	Build(Root<<1,L,mid);
	Build(Root<<1|1,mid+1,R);
	PushUp(Root);
}

int Query(int Root,int L,int R,int now_l,int now_r){
	if(L<=now_l && now_r<=R) 
		return sum[Root];
	int mid=now_l+now_r>>1,ans=2e9;
	if(L<=mid)
		ans=min(ans,Query(Root<<1,L,R,now_l,mid));
	if(R>mid)
		ans=min(ans,Query(Root<<1|1,L,R,mid+1,now_r));
	return ans;
}

int main(){
    int n,q,x,y;
    qr(n); qr(q);
    for(int i=1;i<=n;i++)
        qr(a[i]);
    Build(1,1,n);
    while(q--){
        qr(x); qr(y);
        printf("%d\n",Query(1,x,y,1,n));
    }
    return 0;
}