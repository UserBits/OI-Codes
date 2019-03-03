#include<iostream>
#include<cstdio>
using namespace std;
int array[15];
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=m;i<=n;i++)
    {
        int p=i;
        while(p)
        {
            array[p%10]++;
            p/=10;
        }
    }
    for(int i=0;i<10;i++)
        printf("%d ",array[i]);
    return 0;
}
