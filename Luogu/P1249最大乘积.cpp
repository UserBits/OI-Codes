#include <cstdio>
#include <cstring>
using namespace std;
int ans[30005];
inline void calc(int len)
{
	int a[10005]={0,1},b[10005],c[10005],lena=1,lenb=1,lenc;
	for(int t=0;t<len;t++)
	{
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int n=ans[t];
	lenb=1;
	while(n)
	{

		b[lenb++]=n%10;
		n/=10;
	}
	int up=0;
	for(int i=1;i<=lena;i++)
	{
		up=0;
		for(int j=1;j<=lenb;j++)
		{
			c[i+j-1]=c[i+j-1]+a[i]*b[j]+up;
			up=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+lenb]=up;
	}
	lenc=lena+lenb;
	while(c[lenc]==0 && lenc>0)
		lenc--;
	for(int i=lenc;i>0;i--)
		a[i]=c[i];
	lena=lenc;
	}
	for(int i=lena;i>0;i--)
		printf("%d",a[i]);

}
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("1\n"); return 0;}
	if(n==2){
		printf("0\n"); return 0;}
	if(n==3)
	{
		printf("2\n");
		return 0;
	}
	if(n==4){
		printf("3\n");
		return 0;
	}
	int i=0,x=2,j,t=0,k=n;
	while(n>=x)
	{
		ans[i++]=x;
		n-=x;
		t+=x;
		x++;
	}
	while(t<k){
		for(j=i-1;n>0 && j>=0;j--,n--)
			ans[j]++;
		t=0;
 		for(j=0;j<i;j++)
			t+=ans[j];

	}
	for(int len=0;len<i;len++)
		printf("%d ",ans[len]);
	putchar('\n');
	calc(i);
	return 0;
}

