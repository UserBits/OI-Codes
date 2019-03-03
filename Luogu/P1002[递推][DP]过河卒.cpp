#include<cstdio>
const int MAXN=110;
bool b[MAXN][MAXN];
long long a[MAXN][MAXN];
int dx[8]={2,1,-1,-2,-2,-1,1,2},dy[8]={1,2,2,1,-1,-2,-2,-1};
int main()
{
    for(int i=0;i<110;i++)
	{
		for(int j=0;j<110;j++)
			b[i][j]=0;
	}
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    b[x][y]=1;
    for(int i=0;i<8;i++)
    {
        if(x+dx[i]>=0 && x+dx[i]<=n && y+dy[i]>=0 && y+dy[i]<=m)
			b[x+dx[i]][y+dy[i]]=1;
    }
    int k=0;
    while(!b[k][0] && k<=n)
        a[k++][0]=1;
    int l=0;
    while(!b[0][l] && l<=m)
        a[0][l++]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j])
				a[i][j]=0;
            else
				a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    printf("%lld\n",a[n][m]);
    return 0;
}
