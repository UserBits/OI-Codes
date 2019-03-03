#include <cstdio>
using namespace std;
int h,k,ans[20005],t;
int main()
{
    scanf("%d%d",&h,&k);
    ans[0]=k+1;
    t=ans[0]+k+1;
    for(int i=1;i<=h;i++)
    {
        ans[i]=t;
        t+=ans[i];
    }
    printf("%d\n",ans[h]);
    return 0;
}
