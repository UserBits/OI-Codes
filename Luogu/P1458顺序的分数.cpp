#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int a,b;
	double value;
}array[100005];
bool cmp(node a,node b)
{
	return a.value<b.value;
}
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(j!=0 && gcd(i,j)==1)
			{
				array[ans].a=i;
				array[ans].b=j;
				array[ans].value=i*1.0/j;
				ans++;
			}
		}
	}
	sort(array,array+ans,cmp);
	for(int i=0;i<ans;i++)
		printf("%d/%d\n",array[i].a,array[i].b);
	return 0;
}

