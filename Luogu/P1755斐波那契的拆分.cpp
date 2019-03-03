#include<iostream>
using namespace std;
int a[60],i,j,x,t,tot,pd,b[60],all;
void work(int k)
{
	if(k==0)
	{
		pd=1;
		return;
	}
	for(int i=all; i>=1; i--)
	{
		while(k-a[i]>=0)
		{
			k-=a[i];
			b[++tot]=a[i];
			work(k);
			if(pd==1)
				return;
			tot--;
			k+=a[i];
		}
	}
}
int main()
{
	a[1]=1;
	a[2]=2;
	i=3;
	while(a[i-1]<=(1<<30))
	{
		a[i]=a[i-1]+a[i-2];
		i++;
	}
	all=i-1;
	cin>>t;
	for(i=1; i<=t; i++)
	{
		cin>>x;
		pd=0;
		cout<<x<<"=";
		work(x);
		for(j=tot; j>=2; j--)
		{
			cout<<b[j]<<"+";
			b[j]=0;
		}
		cout<<b[1]<<endl;
		b[tot]=0;
		tot=0;
	}
}

