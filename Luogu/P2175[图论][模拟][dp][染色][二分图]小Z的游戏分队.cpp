#include <cstdio>
#include <cstring>
#include <cstdlib>

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

const int N=2000;
struct Edge{
	int node,next;
}edge[N*N+5];
int head[N+5],n,tot;
inline void add(int x,int y){
	edge[++tot].node=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

int col[N+5],a[N][2],block;
void dfs(int u,int c){
	if(col[u]!=-1){
		if(c!=col[u]){
			puts("No solution");
			exit(0);
		}
		return;
	}
	col[u]=c;
	a[block][c]++;
	for(int k=head[u];k;k=edge[k].next)
		dfs(edge[k].node,1^c);
}

bool trust[N+1][N+1],dp[N+5][2*N+5];
#define f(x,y) dp[x][y+N]
int main(){
	qr(n);
	for(int i=1,j;i<=n;++i){
		qr(j);
		while(j){
			trust[i][j]=1;
			qr(j);
		}
	}
	for(int i=1,j;i<=n;++i){
		for(j=1;j<i;++j){
			if(!(trust[i][j]&&trust[j][i]))
				add(i,j),add(j,i);
		}
	}
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;++i){
		if(col[i]==-1){
			++block;
			dfs(i,0);
		}
	}
	f(0,0)=1;
	for(int i=1,j;i<=block;++i){
		for(j=-N;j<=N;++j)
			f(i,j)|=f(i-1,j-a[i][0]+a[i][1])|f(i-1,j+a[i][0]-a[i][1]);
	}
	for(int i=0;i<=2000;++i){
		if(f(block,i)||f(block,-i)){
			int x=(n+i)>>1;
			int y=n-x;
			if(x>y)
				x^=y^=x^=y;
			printf("%d %d\n",x,y);
			return 0;
		}
	}
	return 0;
}