#include <cstdio>
int dis[105][105],f[1000005];
int main(){
	int n,m,sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&f[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	for(int i=2;i<=m;i++)
		sum+=dis[f[i-1]][f[i]];
	printf("%d\n",sum);
	return 0;
}

