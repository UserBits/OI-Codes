#include<iostream>
#include<cstdio>
int a[10000005];
int main()
{
    int n,s=1,maxn=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>a[i-1])
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
