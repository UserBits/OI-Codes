#include <cstdio>
using namespace std;
int ans=1,n=0;
void set(int a)
{
	if(a==1)
		return;
	int k=1;
	while(k<=a/2)
	{
		set(k);
		ans++;
		k++;
	}
}
int main()
{
	scanf("%d",&n);
	set(n);
	printf("%d",ans);
	return 0;
}
