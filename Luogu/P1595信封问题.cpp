#include <cstdio>
using namespace std;
int f[25];
int main()
{
	f[1]=0;
	f[2]=1;
	f[3]=2;
	for(int i=4;i<21;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	int n;
	scanf("%d",&n);
	printf("%d\n",f[n]);
}
