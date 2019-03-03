#include <cstdio>
using namespace std;
int i,j,t,m,tmp[10005],ptr[10005],f[100005],max_value=0;
inline int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
    scanf("%d%d",&t,&m);
    for(i=1;i<=m;i++)
        scanf("%d%d",&tmp[i],&ptr[i]);
    for(i=1;i<=m;i++)
    {
        for(j=tmp[i];j<=t;j++)
        {
            f[j]=max(f[j],f[j-tmp[i]]+ptr[i]);
            if(f[j]>max_value)
            	max_value=f[j];
        }
    }
    printf("%d\n",max_value);
    return 0;
}

