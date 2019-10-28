#include <cstdio>

inline int mx(int x,int y){
	return x>y?x:y;
}

int f[501][501],g[501][501];
//f[i][j]ǰi�ˣ�ѡj�Σ���i��ѡ
//g[i][j]...........��ѡ
int main(){
	int n,k,x,s=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		for(int j=1;j<=k;j++){
			f[i][j]=mx(f[i-1][j],g[i-1][j-1])+x;
			g[i][j]=mx(f[i-1][j],g[i-1][j]);
		}
	}
	for(int i=1;i<=k;i++)
		s=mx(s,mx(f[n][i],g[n][i]));
	printf("%d\n",s);
	return 0;
}
