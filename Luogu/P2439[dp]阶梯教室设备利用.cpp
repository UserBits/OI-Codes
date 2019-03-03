#include <cstdio>
#include <cstring>
int b[10005],e[10005],f[10005],ans;
template < typename __Max_Type >
inline __Max_Type max ( __Max_Type x, __Max_Type y)
{
    return x>y?x:y;
}
void qsort(int l,int r)
{
	int i,j,m,p;
	i=l;
	j=r;
	m=b[(l+r)>>1];
	do
	{
        while(b[i]<m)
            i++;
        while(b[j]>m)
            j--;
        if(i<=j)
        {
            p=b[i];b[i]=b[j];b[j]=p;
            p=e[i];e[i]=e[j];e[j]=p;
            i++;
            j--;
        }
	}
	while(i<=j);
	if(i<r)
        qsort(i,r);
	if(l<j)
        qsort(l,j);
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        scanf("%d%d",&b[i],&e[i]);
	qsort(1,n);
	memset(f,-127,sizeof(f));
	for(i=1;i<=n;i++)
        f[i]=e[i]-b[i];
	for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            if(b[i]>=e[j])
                f[i]=max(f[i],f[j]+e[i]-b[i]);
        }
    }
	ans=0;
	for(i=1;i<=n;i++)
    {
        if(f[i]>ans)
            ans=f[i];
    }
	printf("%d\n",ans);
}