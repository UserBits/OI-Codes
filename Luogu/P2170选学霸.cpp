#pragma G++ optimize(O2)
#include <cstdio>
const int N=20005;
int f[N],p[N],a[N];
bool dp[N];
int Find(int x)
{
    if(f[x]==x) return f[x];
    f[x]=Find(f[x]);
    return f[x];
}
inline void Merge(int x,int y){
	int i=Find(x),j=Find(y);
	if(i!=j)
		f[i]=f[j];
}
inline int Abs(int x){
	return x>0?x:-x;
}
int main(){
	int n,m,k,x,y;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		f[i]=i;
	while(k--){
		scanf("%d%d",&x,&y);
		Merge(x,y);
	}
	for(int i=1;i<=n;i++)
		f[i]=Find(f[i]);
	for(int i=1;i<=n;i++)
		p[f[i]]++;
	int len=0;
	for(int i=1;i<=n;i++){
		if(p[i])
			a[++len]=p[i];
	}
	dp[0]=1;
	for(int i=1;i<=len;i++){
		for(int j=n;j>=a[i];j--)
			dp[j]=dp[j]||dp[j-a[i]];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(dp[i] && Abs(i-m)<Abs(ans-m))
			ans=i;
	}
	printf("%d\n",ans);
	return 0;
}
