#include <iostream>
using namespace std;
int k,u,l,ans,f,r,mx,c;
int m[126005],n;
int a[10005],b[10005];
int main()
{
	cin>>u>>k;
	for (int i=0; i<=k; i++)
		for (int j=0; j<=k; j++)
			m[i*i+j*j]=1;
	n=k*k*2;
	for (int i=0; i<=n; i++)
	{
		c=(n-i)/(u-1);
		if (m[i])
		{
			for (int j=1; j<=c; j++)
			{
				l=j;
				f=u;
				while (f-1)
				{
					if (m[i+l*(u-f)]==m[i+l*(u-f+1)])
						f--;
					else
						break;
				}
				if (f-1==0)
				{
					ans++;
					a[ans]=i;
					b[ans]=l;
				}
			}
		}
	}
	for (int i=1; i<=ans; i++)
		for (int j=1; j<=ans; j++)
		{
			if (b[i]>b[j] || b[i]==b[j] && a[i]>a[j])
			{
				r=b[i];
				b[i]=b[j];
				b[j]=r;
				r=a[i];
				a[i]=a[j];
				a[j]=r;
			}
		}
	if (ans==0)
		cout<<"NONE"<<endl;
	else
		for (int i=ans; i>=1; i--)
			cout<<a[i]<<" "<<b[i]<<endl;
	return 0;
}

