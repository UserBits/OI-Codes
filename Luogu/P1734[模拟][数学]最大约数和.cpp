#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int p[100005],f[100005];
void work()
{
    for(int i=1;i<=1000;i++)
    {
    	int maxn=sqrt(i);
        for(int j=1;j<=maxn;j++){
          	if(i%j==0)
          	{
              	p[i]+=j;
              	if(j*j!=i)
			  		p[i]+=(i/j);
          	}
      	}
      	p[i]-=i;
    }
}
int main()
{
    work();
    int s;
    scanf("%d",&s);
    for(int i=2;i<=s;i++)
    {
     	for(int j=s;j>=i;j--)
      		f[j]=max(f[j],f[j-i]+p[i]);
    }
    printf("%d\n",f[s]);
    return 0;
}
