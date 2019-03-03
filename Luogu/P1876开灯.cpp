#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i*i<=n;i++)
        printf("%d ",i*i);
    return 0;
}
