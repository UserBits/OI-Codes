#include<cstdio>
int n,p,q,t;
int main()
{
	//freopen("testdata.in","r",stdin);
    for(scanf("%d",&n);~scanf("%d",&p);t^=1)
    {
        for(;p--;q++)
		{
            if(q==n)
				q=0&putchar(10);
			putchar(48+t);
        }
    }
    return 0;
}
