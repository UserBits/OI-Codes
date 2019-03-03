#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
    int n,j=0,maxn=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for (int k=1;k<=5;k++)
    {
        int s=0;
        for(int i=0;i<n;i++)
        {

            if(a[i]==k || b[i]==k)
                s++;
            if (a[i]!=k && b[i]!=k)
            {
                if(s>=maxn)
                {
                    maxn=s;
                    j=k;
                }
                s=0;
            }
        }
        if (s>maxn)
        {
            maxn=s;
            j=k;
        }
    }
    printf("%d %d",maxn,j);
    return 0;
}
