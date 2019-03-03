#include <cstdio>

inline int mn(int x,int y){
	return x<y?x:y;
}
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename Tp>
inline void qr(Tp &s){
    char c=gc(); s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
}

const int N=1501;
struct Ed{
	int nd,nx;
}ed[N<<1];
int hd[N],tot,f[N],g[N];
inline void add(int x,int y){
	ed[++tot].nd=++y;
	ed[tot].nx=hd[++x]; hd[x]=tot;
}

void dfs(int cur,int last){
	f[cur]=1; g[cur]=0;
	for(int k=hd[cur],x;k;k=ed[k].nx){
		x=ed[k].nd;
		if(x==last) continue;
		dfs(x,cur);
		f[cur]+=mn(f[x],g[x]);
		g[cur]+=f[x];
	}
}

int main(){
	int n,x,y,t;
	qr(n);
	while(n--){
		qr(x); qr(t);
		while(t--){
			qr(y);
			add(x,y); add(y,x);
		}
	}
	dfs(1,0);
	printf("%d\n",mn(f[1],g[1]));
	return 0;
}
