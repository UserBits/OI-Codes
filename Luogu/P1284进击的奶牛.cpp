#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005],n,c,p;
inline bool check(int val)
{
    int cnt=0,last=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]-last<val)
            cnt++;
        else
            last=a[i];
        if(cnt>p)
            return 0;
    }
    return 1;
}
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    p=n-c;
    sort(a+1,a+1+n);
    int l=1,r=a[n]-a[1],mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    if(check(r))
        printf("%d\n",r);
    else
        printf("%d\n",l);
    return 0;
}
