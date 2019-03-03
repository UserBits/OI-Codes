#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 20000
using namespace std;
int n;
int start,en,sum;
struct node
{
    int x,y;
}a[maxn];
int cmp(node u,node v)
{
    return u.x<v.x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1,cmp);
    start=a[1].x;
    en=a[1].y;
    sum+=a[1].y-a[1].x;
    for(int i=2;i<=n;i++)
    {
        if(a[i].x<=en)
        {
            if(a[i].y<en) continue;
            else
            {
                start=en;
                en=a[i].y;
                sum+=en-start;
            }
        }
        if(a[i].x>en)
        {
            start=a[i].x;
            en=a[i].y;
            sum+=en-start;
        }
    }
    cout<<sum<<endl;
    return 0;
}
