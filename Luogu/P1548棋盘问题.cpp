#include <cstdio>
using namespace std;
int main()
{
	//freopen("rect.in","r",stdin);
	//freopen("rect.out","w",stdout);
	int n,m,s,t,a,b,c;
	s=t=0;
	scanf("%d%d",&n,&m);
	a=1,b=1,c=(m*(m-1))>>1;
	while(a<=n)
	{
		if(a==b)
			s=s+(n-a+1)*(m-b+1);
		t+=(n-a+1)*(c+b-1);
		if(a<=n)
			a++;
		if(b<=m)
			b++;
	}
	printf("%d %d\n",s,t);
	return 0;
}

