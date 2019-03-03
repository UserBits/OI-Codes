#include <cstdio>
using namespace std;
int main()
{
    int t;
	scanf("%d",&t);
    printf("%d\n",t);
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i%2==1)
                printf("0");
            else
                printf("1");
        }
        for(int j=i+1;j<=t;j++)
        {
            if(i%2==1)
                printf("1");
            else
                printf("0");
        }
		printf("\n");
    }
    return 0;
}

