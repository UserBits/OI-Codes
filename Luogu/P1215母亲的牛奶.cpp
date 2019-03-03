#include<cstdio>
#include<cstring>
using namespace std;
int a[4],f[21];
int m[400][5];
bool bz[21][21][21];
int head=0,tail=1;
int main()
{
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	m[1][1]=a[3];
	memset(bz,true,sizeof(bz));
	memset(f,0,sizeof(f));
	bz[0][0][a[3]]=false;
	while(head<tail)
	{
		head++;
		for(int x=1; x<=3; x++)
		{
			for(int y=1; y<=3; y++)
			{
				if(x!=y && m[head][x]>0 && m[head][y]<a[y])
				{
					tail++;
					for(int i=0; i<=4; i++)
						m[tail][i]=m[head][i];
					if(m[tail][x]<=a[y]-m[tail][y])
					{
						m[tail][y]=m[tail][y]+m[tail][x];
						m[tail][x]=0;
					}
					else
					{
						m[tail][y]=a[y];
						m[tail][x]=m[tail][x]-(a[y]-m[head][y]);
					}
					if(bz[m[tail][1]] [m[tail][2]] [m[tail][3]])
					{
						bz[m[tail][1]] [m[tail][2]] [m[tail][3]]=false;
						m[tail][4]++;
						if(m[tail][1]==0) f[m[tail][3]]++;
					}
					else tail--;
				}
			}
		}
	}
	for(int i=0; i<=20; i++)
		if(f[i]>0) printf("%d ",i);
	printf("%d",a[3]);
}

