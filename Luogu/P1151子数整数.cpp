#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int k;
    bool p=0;
    scanf("%d",&k);
    for(int i=10000;i<=30000;i++)
    {
        int a=i/100,b=i/10%1000,c=i%1000;
        if(a%k==0 && b%k==0 && c%k==0)
        {
            printf("%d\n",i);
            p=1;
        }
    }
    if(p==0)
        printf("No\n");
    return 0;
}
