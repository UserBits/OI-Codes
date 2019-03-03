#include <cstdio>
using namespace std;
int a[100005],n,k;
inline bool check(int t)
{
    int s=0;
    for(int i=1;i<=n;i++)
        s+=a[i]/t;
    return s>=k;
}
int main()
{
    scanf("%d%d",&n,&k);
    double tp;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&tp);
        a[i]=(int)(tp*100);
    }
    int l=1,r=1000000000,ans,mid;
    while(l<=r)
    {
        mid=l+r>>1;
        if(!mid)
            break;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
    }
    printf("%.2lf\n",ans/100.0);
    return 0;
}
