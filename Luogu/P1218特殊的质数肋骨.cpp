#include <cstdio>
using namespace std;
int p[4]={2,3,5,7},q[4]={1,3,7,9},len;
bool prime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
    	if(n%i==0)
    		return 0;
    }
    return 1;
}
void dfs(int s,int i)
{
    int tmp;
    if(i==len)
    {
       printf("%d\n",s);
        return;
    }
    for(int j=0;j<4;j++)
    {
        tmp=s*10+q[j];
        if(prime(tmp))
			dfs(tmp,i+1);
    }
}
int main()
{
    scanf("%d",&len);
    if(len==1)
    {
    	printf("2\n3\n5\n7\n");
    	return 0;
	}
    else
    {
        for(int i=0;i<4;i++)
        	dfs(p[i],1);
    }
    return 0;
}
