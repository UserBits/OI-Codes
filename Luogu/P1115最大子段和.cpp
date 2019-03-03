#include<iostream>
#include<cstdio>
using namespace std;
int a[200005];
int main()
{
    int n,sum,max;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    max=sum=a[0];
    for(int i=1;i<n;i++)
    {
        if(sum<0)
            sum=0;
        sum+=a[i];
        if(sum>max)
            max=sum;
    }
    cout<<max<<endl;
    return 0;
}
