#include <cstdio>

template<typename r_e_a_d>
inline void qr(r_e_a_d &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
template<typename w_r_i_t_e>
inline void wr(w_r_i_t_e x){
	if(x>9)
		wr(x/10);
	putchar(x%10+48);
}

const int N=100005;
typedef long long ll;
ll sum[4*N],add[4*N],a[N];

inline void PushUp(int Root){ //累计
	sum[Root]=sum[Root<<1]+sum[Root<<1|1];
}
inline void PushDown(int Root,int Ln,int Rn){ //将根的权值转移向孩子节点
	if(add[Root]){
		add[Root<<1]+=add[Root];
		add[Root<<1|1]+=add[Root];
		//总和即为: 累加的和*长度
		sum[Root<<1]+=add[Root]*Ln;
		sum[Root<<1|1]+=add[Root]*Rn;
		add[Root]=0;
	}
}

void Build(int Root,int L,int R){ //建树
	if(L==R){
		sum[Root]=a[L];
		return;
	}
	int mid=L+R>>1;
	Build(Root<<1,L,mid);
	Build(Root<<1|1,mid+1,R);
	PushUp(Root);
}

void Update(int Root,int L,int R,int V,int now_l,int now_r){
	//Root: 当前节点 L: 求解的区间的左端点 R: 求解的区间的右端点
	//V: 累加的值 now_l: 当前左端点 now_r: 当前右端点
	if(L<=now_l && now_r<=R){
		sum[Root]+=V*(now_r-now_l+1);
		add[Root]+=V;
		return;
	}
	int mid=now_l+now_r>>1;
	PushDown(Root,mid-now_l+1,now_r-mid);
	if(L<=mid)
		Update(Root<<1,L,R,V,now_l,mid);
	if(R>mid)
		Update(Root<<1|1,L,R,V,mid+1,now_r);
	PushUp(Root);
}

ll Query(int Root,int L,int R,int now_l,int now_r){
	if(L<=now_l && now_r<=R) //当前区间已经被包含在求解的区间内
		return sum[Root];
	int mid=now_l+now_r>>1;
	PushDown(Root,mid-now_l+1,now_r-mid); //向下更新
	ll ans=0;
	if(L<=mid)
		ans+=Query(Root<<1,L,R,now_l,mid);
	if(R>mid)
		ans+=Query(Root<<1|1,L,R,mid+1,now_r);
	return ans;
}

int main(){
	int n,m;
	qr(n); qr(m);
	for(int i=1;i<=n;i++)
		qr(a[i]);
	Build(1,1,n);
	int opt,x,y,k;
	while(m--){
		qr(opt);
		if(opt==1){
			qr(x); qr(y); qr(k);
			Update(1,x,y,k,1,n);
		}
		else{
			qr(x); qr(y);
			wr(Query(1,x,y,1,n));
			putchar('\n');
		}
	}
	return 0;
}
