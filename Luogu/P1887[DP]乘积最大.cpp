#include <cstdio>
int main()
{
    int a,b,n,ans;
    scanf("%d%d",&a,&b);
    n=a%b;
    ans=a/b;
    for(int i=n;i<b;i++)
       	printf("%d ",ans);
    for(int i=0;i<n;i++)
        printf("%d ",ans+1);
    return 0;
}
