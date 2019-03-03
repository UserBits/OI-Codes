#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[130000];
int main()
{
	int n,s=0,t=0,b,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
        b=1;
        scanf("%d",&x);
        if(x>=a[t])
        {
            while(x>a[t] && t>0)
            {
                s++;
                t--;
            }
            while(x==a[t] && t>0)
            {
                t--;
                s++;
                b++;
            }
        }
        if(t!=0)
			s++;
        t+=b;
        a[t]=x;
    }
    printf("%d\n",s);
    return 0;
}
