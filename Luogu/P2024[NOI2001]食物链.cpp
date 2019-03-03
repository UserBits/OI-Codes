#include <cstdio>
int f[300005],n,k;
inline int Find(int x){
	if(x!=f[x])
		f[x]=Find(f[x]);
	return f[x];
}
inline void Union(int x,int y){
	int a=Find(f[x]),b=Find(f[y]);
	f[a]=b;
}
int main(){
	//freopen("testdata.in","r",stdin);
	int p,x,y,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=3*n;i++)
		f[i]=i;
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&p,&x,&y);
		if(x>n||y>n){
			ans++;
			continue;
		}
		if(p==1){
			if(Find(x+n)==Find(y)||Find(x+2*n)==Find(y)){
				ans++;
				continue;
			}
			Union(x,y);
			Union(x+n,y+n);
			Union(x+2*n,y+2*n);
		}
		if(p==2){
			if(x==y){
				ans++;
				continue;
			}
			if(Find(x)==Find(y)||Find(x+2*n)==Find(y)){
				ans++;
				continue;
			}
			Union(x,y+2*n);
			Union(x+n,y);
			Union(x+2*n,y+n);
		}
	}
	printf("%d\n",ans);
	return 0;
}
