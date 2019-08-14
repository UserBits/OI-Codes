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

const int N=200005;
struct Edge{
	int node,next;
}edge[N];
int head[N<<1],f[N<<1],num[N<<1],n,m,tot,block,u[N],v[N],k,d[N<<1],ans[N<<1];

inline void add(int x,int y){
	edge[++tot].node=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

int Get(int x){
	if(x==f[x])
		return x;
	return f[x]=Get(f[x]);
}

void Merge(int x,int y){
	x=Get(x);
	y=Get(y);
	if(x==y)
		return;
	f[x]=y; block--;
}

int main(){
	qr(n); qr(m);
	for(int i=1;i<=m;i++){
		qr(u[i]); qr(v[i]);
		++u[i],++v[i];
	}
	qr(k);
	for(int i=1;i<=k;i++){
		qr(d[i]);
		d[i]++;
		num[d[i]]=k-i+1;
	}
	for(int i=1;i<=k/2;i++){
		int t=d[i];
		d[i]=d[k-i+1];
		d[k-i+1]=t;
	}
	for(int i=1;i<=m;i++){
		if(num[u[i]]>num[v[i]])
			add(u[i],v[i]);
		else
			add(v[i],u[i]);
	}
	block=n;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		if(!num[u[i]]&&!num[v[i]])
			Merge(u[i],v[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=head[d[i]];j;j=edge[j].next)
			Merge(d[i],edge[j].node);
		ans[i]=block-(k-i);
	}
	for(int i=k;~i;i--)
		printf("%d\n",ans[i]);
	return 0;
}
