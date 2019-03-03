#include <cstdio>
using namespace std;
int a[10005];
void work(int p)
{
	int temp=p;
	for(int i=2;i<=p;i++)
	{
		if(p==1)
			break;
		else
		{
			while(temp%i==0)
			{
				a[i]++;
				temp/=i;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		work(i);
	for(int i=2;i<10001;i++)
	{
		if(a[i])
			printf("%d %d\n",i,a[i]);
	}
	return 0;
}

