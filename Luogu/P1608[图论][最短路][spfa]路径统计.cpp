#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename qd>
inline void qr(qd &s){
    char c=gc(); s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c^48);
}

const int N=2001;
int val[N][N],dis[N],cnt[N],n,m,i,u,v;
bool inq[N];
void spfa(int st,int ed){
	for(i=1;i<=n;++i)
		dis[i]=1e9;
	queue<int> q; q.push(st);
	dis[st]=0; inq[st]=1; cnt[st]=1;
	while(!q.empty()){
		u=q.front(); q.pop(); inq[u]=0;
		if(u==ed) continue;
		for(v=1;v<=n;++v){
			if(dis[v]==dis[u]+val[u][v])
				cnt[v]+=cnt[u];
			if(dis[u]+val[u][v]<dis[v]){
				dis[v]=dis[u]+val[u][v];
				cnt[v]=cnt[u];
			}
			if(cnt[v] && !inq[v]){
				inq[v]=1; q.push(v);
			}
		}
		cnt[u]=0;
	}
}

int main(){
	qr(n); qr(m);
	for(u=1;u<=n;++u){
		for(v=1;v<=n;++v)
			val[u][v]=1e9;
	}
	while(m--){
		qr(u); qr(v); qr(i);
		val[u][v]=min(val[u][v],i);
	}
	spfa(1,n);
	if(dis[n]<1e9)
		printf("%d %d\n",dis[n],cnt[n]);
	else
		puts("No answer");
	return 0;
}
