#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int len=0,n,ans=0,len1=0;
long long a[1005]={0},b[1005]={0};
void jiecheng(int x)
{
	int d,r;
	d=0;
	for(int i=1; i<=len; i++)
	{
		r=a[i];
		a[i]=(a[i]*x+d)%10000;
		d=(r*x+d)/10000;
	}
	if(d!=0)
		a[++len]=d;
}
void jiafa(int k)
{
	int d,r;
	d=0;
	for(int i=1; i<=k; i++)
	{
		r=b[i];
		b[i]=(b[i]+a[i]+d)%10000;
		d=(r+a[i]+d)/10000;
	}
	if(d!=0)
	{
		b[++k]=d;
		len1=k+1;
	}
	else
		len1=k;
}
int main()
{

	cin>>n;
	len=1;
	a[1]=1;
	len1=0;
	for(int i=1; i<=n; i++)
	{
		memset(a,0,sizeof(a));
		a[1]=1;
		len=1;
		for(int j=1; j<=i; j++)
			jiecheng(j);
		if(len1>len)
			jiafa(len1);
		else
			jiafa(len);
	}
	for(int i=len1; i>=1; i--)
	{
		if(i!=len1)
			if(b[i]/1000==0)
				cout<<0;
		cout<<b[i];
	}
	return 0;
}

