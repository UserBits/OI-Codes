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

inline void PushUp(int Root){ //�ۼ�
	sum[Root]=sum[Root<<1]+sum[Root<<1|1];
}
inline void PushDown(int Root,int Ln,int Rn){ //������Ȩֵת�����ӽڵ�
	if(add[Root]){
		add[Root<<1]+=add[Root];
		add[Root<<1|1]+=add[Root];
		//�ܺͼ�Ϊ: �ۼӵĺ�*����
		sum[Root<<1]+=add[Root]*Ln;
		sum[Root<<1|1]+=add[Root]*Rn;
		add[Root]=0;
	}
}

void Build(int Root,int L,int R){ //����
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
	//Root: ��ǰ�ڵ� L: �����������˵� R: ����������Ҷ˵�
	//V: �ۼӵ�ֵ now_l: ��ǰ��˵� now_r: ��ǰ�Ҷ˵�
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
	if(L<=now_l && now_r<=R) //��ǰ�����Ѿ�������������������
		return sum[Root];
	int mid=now_l+now_r>>1;
	PushDown(Root,mid-now_l+1,now_r-mid); //���¸���
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
