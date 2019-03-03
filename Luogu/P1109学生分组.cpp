#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int student[60];
int main()
{
	int n,l,r,x=0,y=0,all=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&student[i]);
	scanf("%d%d",&l,&r);
	for(int i=0;i<n;i++)
		all+=student[i];
	if(all<n*l || all>n*r)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(student[i]<l)
			x+=l-student[i];
		if(student[i]>r)
			y+=student[i]-r;
	}
	cout<<max(x,y)<<endl;
	return 0;
}
