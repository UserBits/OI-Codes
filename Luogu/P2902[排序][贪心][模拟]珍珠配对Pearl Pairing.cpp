#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
    int col,tot;
}a[100005];
int ans[200005];
bool cmp(node x,node y)
{
    if(x.tot!=y.tot)
        return x.tot<y.tot;
    return x.col<y.col;
}
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=c;i++)
    {
        a[i].col=i;
        scanf("%d",&a[i].tot);
    }
    sort(a+1,a+1+c,cmp);
    int len=1;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=a[i].tot;j++)
        {
            ans[len]=a[i].col;
            len++;
        }
    }
    n>>=1;
    for(int i=1;i<=n;i++)
        printf("%d %d\n",ans[i],ans[i+n]);
    return 0;
}
