#include <cstdio>
int f[2005][2005],s[2005][2005];
int main(){
	int t,k;
	scanf("%d%d",&t,&k);
	f[0][0]=1;
	for(int i=1;i<=2000;i++){
		f[i][0]=1;
		for(int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j]+f[i-1][j-1])%k;
	}
	for(int i=1;i<=2000;i++){
		for(int j=1;j<=i;j++){
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			if(f[i][j]==0)
				s[i][j]++;
		}
		for(int j=i+1;j<=2000;j++)
			s[i][j]=s[i][i];
	}
	int n,m;
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n",s[n][m]);
	}
	return 0;
}
