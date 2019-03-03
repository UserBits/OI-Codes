#include <cstdio>
using namespace std;
int a[200],b[200],c[200];
int main()
{
  	int n,i,j,maxn;
  	scanf("%d",&n);
  	for(i=1;i<=n;i++)
   		scanf("%d",&a[i]);
  	for(i=1;i<=n;i++)
   	{
    	b[i]=1;
     	for(j=1;j<=i-1;j++)
     	{
      		if(a[i]>a[j] && b[j]+1>b[i])
       			b[i]=b[j]+1;
		}
   	}
	for(i=n;i>=1;i--)
   	{
    	c[i]=1;
     	for(j=i+1;j<=n;j++)
     	{
      		if(a[j]<a[i] && c[j]+1>c[i])
        		c[i]=c[j]+1;
        }
   	}
  	maxn=0;
  	for(i=1;i<=n;i++)
  	{
    	if(b[i]+c[i]>maxn)
       		maxn=b[i]+c[i];
    }
  	printf("%d\n",n-maxn+1);
  	return 0;
}

