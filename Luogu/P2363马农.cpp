#include <cstdio>
#include <cstring>
using namespace std;
const int m=2500000;
int n,sum[55][55],ans,x,tmp,top,h[m*2+10],st[55*55];
int main()
{
	scanf("%d",&n);
	ans=top=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%d",&x);
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+x;
		}
	}
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<n; j++)
		{
			for(int k=1; k<=i; k++)
			{
				for(int l=1; l<=j; l++)
				{
					tmp=sum[i][j]+sum[k-1][l-1]-sum[k-1][j]-sum[i][l-1]+m;
					st[top++]=tmp;
					h[tmp]++;
				}
			}
			for(int k=i+1; k<=n; k++)
			{
				for(int l=j+1; l<=n; l++)
				{
					tmp=sum[i][j]+sum[k][l]-sum[k][j]-sum[i][l]+m;
					ans+=h[tmp];
				}
			}
			while(top)
		    	h[st[--top]]=0;
			for(int k=i+1; k<=n; k++)
			{
				for(int l=1; l<=j; l++)
				{
					tmp=sum[i][l-1]+sum[k][j]-sum[i][j]-sum[k][l-1]+m;
					st[top++]=tmp;
					h[tmp]++;
				}
			}
			for(int k=1; k<=i; k++)
			{
				for(int l=j+1; l<=n; l++)
				{
					tmp=sum[i][l]+sum[k-1][j]-sum[k-1][l]-sum[i][j]+m;
			    	ans+=h[tmp];
				}
			}
			while(top)
				h[st[--top]]=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}

