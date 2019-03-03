// luogu-judger-enable-o2
#include <cstdio>
using namespace std;
int a[60];
void dfs(int n)
{
    int i=0;
    if(n!=0)
    {
        while(n>=a[i]) i++; i--;
        n-=a[i];
        printf("2");
        if(i!=1)printf("(");
        if(i==0 || i==2)
			printf("%d)",i);
        if(i>=3)
		{
			dfs(i);
			printf(")");
		}
        if(n!=0)
		{
			printf("+");
			dfs(n);
		}
    }
}
int main()
{
    int i,n;
    a[0]=1;
    for(i=1;i<50;i++)
        a[i]=a[i-1]*2;
    scanf("%d",&n);
    dfs(n);
    return 0;
}
