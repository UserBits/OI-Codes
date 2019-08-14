#include <cstdio>
#include <algorithm>

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
inline void qr(int &s){
	s=0;
	char c=gc();
	for(;c<'0'||c>'9';c=gc());
	for(;c>='0'&&c<='9';c=gc())
		s=(s<<1)+(s<<3)+c-'0';
}

inline int mx(int a,int b){
	return a>b?a:b;
}
inline int mn(int a,int b){
	return a<b?a:b;
}

const int M=50005,N=20005;
struct Cow{
	int l,r,p;
	friend bool operator < (Cow x,Cow y){
		return x.r<y.r;
	}
}cow[M];

int tree[N<<2],add[N<<2];
inline void pushup(int rt){
	tree[rt]=mx(tree[rt<<1],tree[rt<<1|1]);
}
inline void pushdown(int rt){
 	if(add[rt]){
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		tree[rt<<1]+=add[rt];
		tree[rt<<1|1]+=add[rt];
		add[rt]=0;
 	}
}

void update(int rt,int l,int r,int v,int now_l,int now_r){
	if(l<=now_l && now_r<=r){
		tree[rt]+=v;
		add[rt]+=v;
		return;
	}
	int mid=now_l+now_r>>1;
	pushdown(rt);
	if(l<=mid)
		update(rt<<1,l,r,v,now_l,mid);
	if(r>mid)
		update(rt<<1|1,l,r,v,mid+1,now_r);
	pushup(rt);
}

int query(int rt,int l,int r,int now_l,int now_r){
	if(l<=now_l && now_r<=r)
		return tree[rt];
	int mid=now_l+now_r>>1,ans=0;
	pushdown(rt);
	if(l<=mid)
		ans=mx(ans,query(rt<<1,l,r,now_l,mid));
	if(r>mid)
		ans=mx(ans,query(rt<<1|1,l,r,mid+1,now_r));
	return ans;
}

int main(){
	int m,n,c;
	qr(m); qr(n); qr(c);
	for(int i=1;i<=m;i++){
		qr(cow[i].l);
		qr(cow[i].r);
		cow[i].r--;
		qr(cow[i].p);
	}
	std::sort(cow+1,cow+1+m);
	int x,y,ans=0;
	for(int i=1;i<=m;i++){
		x=query(1,cow[i].l,cow[i].r,1,n);
		if(x<c){
			y=mn(c-x,cow[i].p);
			ans+=y;
			update(1,cow[i].l,cow[i].r,y,1,n);
		}
	}
	printf("%d\n",ans);
	return 0;
}
