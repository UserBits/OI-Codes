#include <cstdio>
using namespace std;
int main()
{
	int n,i=1;
	scanf("%d",&n);
	while(n>=i+1)
		n-=i++;
	if(i%2)
		printf("%d/%d\n",i+1-n,n);
	else
		printf("%d/%d\n",n,i+1-n);
	return 0;
}

