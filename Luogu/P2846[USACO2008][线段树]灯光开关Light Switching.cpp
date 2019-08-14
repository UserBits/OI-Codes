#include <cstdio>

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

const int N=100001;
int sum[N<<2],add[N<<2];

inline void pushup(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
inline void pushdown(int rt,int len){
    if(add[rt]){
        add[rt<<1]^=1;
        add[rt<<1|1]^=1;
        sum[rt<<1]=len-(len>>1)-sum[rt<<1];
        sum[rt<<1|1]=(len>>1)-sum[rt<<1|1];
        add[rt]=0;
    }
}

void update(int rt,int l,int r,int now_l,int now_r){
    if(l<=now_l && now_r<=r){
        add[rt]^=1;
        sum[rt]=now_r-now_l+1-sum[rt];
        return;
    }
    int mid=now_l+now_r>>1;
    pushdown(rt,now_r-now_l+1);
    if(l<=mid)
        update(rt<<1,l,r,now_l,mid);
    if(r>mid)   
        update(rt<<1|1,l,r,mid+1,now_r);
    pushup(rt);
}

int query(int rt,int l,int r,int now_l,int now_r){
    if(l<=now_l && now_r<=r)
        return sum[rt];
    int mid=now_l+now_r>>1,ans=0;
    pushdown(rt,now_r-now_l+1);
    if(l<=mid)
        ans+=query(rt<<1,l,r,now_l,mid);
    if(r>mid)
        ans+=query(rt<<1|1,l,r,mid+1,now_r);
    return ans;
}

int main(){
    int op,n,m,l,r;
    qr(n); qr(m);
    while(m--){
        qr(op); qr(l); qr(r);
        if(!op)
            update(1,l,r,1,n);
        else
            printf("%d\n",query(1,l,r,1,n));
    }
    //system("pause");
    return 0;
}