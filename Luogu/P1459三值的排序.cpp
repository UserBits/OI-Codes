#include <cstdio>
using namespace std;
int n,a[1005],f=0,g=0,h=0,ans=0;
void swap(int p,int q)
{
	int t=a[p];
	a[p]=a[q];
	a[q]=t;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
			f++;
		if(a[i]==2)
			g++;
		if(a[i]==3)
			h++;
	}
	for(int i=1;i<=f;i++)
	{
		if(a[i]==2)
		{
			for(int j=f+1;j<=n;j++)
			{
				if(a[j]==1)
				{
					swap(i,j);
					ans++;
					break;
				}
			}
		}
		if(a[i]==3)
		{
			for(int j=n;j>f;j--)
			{
				if(a[j]==1)
				{
					swap(i,j);
					ans++;
					break;
				}
			}
		}
	}
	for(int i=f+1;i<=f+g;i++)
	{
		if(a[i]!=2)
		{
			for(int j=f+g+1;j<=n;j++)
			{
				if(a[j]==2)
				{
					swap(i,j);
					ans++;
					break;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

