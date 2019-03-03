#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,s;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    printf("0 ");
    for(int i=1;i<n;i++)
    {
        s=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
                s++;
        }
        printf("%d ",s);
    }
    return 0;
}
