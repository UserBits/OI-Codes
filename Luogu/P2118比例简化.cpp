#include<iostream>
using namespace std;
int main()
{
	double a,b,l,x,y,tmp,max=1<<30;
	cin>>a>>b>>l;
	for(double i=1;i<=l;i++)
	{
		for(double j=1;j<=l;j++)
		{
			tmp=i/j-a/b;
			if(tmp<max && tmp>=0)
			{
				x=i;
				y=j;
				max=tmp;
			}
		}
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}
