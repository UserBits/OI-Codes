#include<iostream>
#include<cstdio>
using namespace std;
int num[10005];
int main()
{
    int n,s=1,maxn=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(int i=0;i<n-1;i++)
    {
        if(num[i]+1==num[i+1])
            s++;
        else
        {
            if(s>maxn)
                maxn=s;
            s=1;
        }
    }
    printf("%d\n",maxn);
    return 0;
}
