#include<iostream>
#include<cstdio>
using namespace std;
bool a[30005];
int main()
{
	//freopen("testdata.in","r",stdin);
	bool x=0;
    int n,k,p,sum=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p);
        a[p]=1;
    }
    for(int i=0;sum<=k && i<30005;i++)
    {
        if(a[i]==1)
        {
            sum++;
            if(sum==k)
            {
            	x=1;
                printf("%d\n",i);
                break;
        	}
        }
    }
    if(x==0)
    	printf("NO RESULT\n");
    return 0;
}
