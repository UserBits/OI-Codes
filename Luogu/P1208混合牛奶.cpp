#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxm 5001
struct milk
{
    int price,account;
};
milk a[maxm];
int n,m,sum,ans;
bool cmp(const milk &x,const milk &y)
{
    return x.price<y.price;
}
int main()
{
    cin>>n>>m;
    sum = n;
    for (int i=0;i<m;++i)
        cin>>a[i].price>>a[i].account;
    sort(a,a+m,cmp);
    for (int i=0;i<m && sum>0 ;++i)
        {
            if (a[i].account <= sum)
                {
                    sum -= a[i].account;
                    ans += a[i].price*a[i].account;
                }
                else
                    {
                        ans += sum * a[i].price;
                        sum = 0;
                    }
        }
    printf("%d",ans);
    return 0;
}
