#include <cstdio>

const int N=801,mod=1e9+7;
int f[N][N][20],g[N][N][20];
//f[i][j][d]ΪСaѡ�˵�(i,j)��ʱ������֮��Ϊd�ķ�����
//g[i][j][d]ΪСuimѡ�˵�(i,j)��ʱ������֮��Ϊd�ķ�����
int main(){
	int n,m,k,x,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	k++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&x);
			x%=k;
			f[i][j][x]=1;//��ֵ���巨
			//Сa��ѡ
			for(int d=0;d<=k;d++){
				f[i][j][d]=(f[i][j][d]+g[i-1][j][(d-x+k)%k])%mod;
				f[i][j][d]=(f[i][j][d]+g[i][j-1][(d-x+k)%k])%mod;
				//�ǰ��Ϊd������һ���Ĳ�Ϊd-x��ע������������ѡ��
				g[i][j][d]=(g[i][j][d]+f[i-1][j][(d+x)%k])%mod;
				g[i][j][d]=(g[i][j][d]+f[i][j-1][(d+x)%k])%mod;
			}
			//printf("%d %d\n",f[i][j][0],g[i][j][0]);
			ans=(ans+g[i][j][0])%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
