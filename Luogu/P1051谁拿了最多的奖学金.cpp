#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	string xm;
	int qm,bj,lw,ans,sum;
	char bgb,xb;
}a[105];
bool cmp(node x,node y)
{
	if(x.ans==y.ans)
		return x.sum<y.sum;
	return x.ans>y.ans;
}
int main()
{
	int n,t=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].xm>>a[i].qm>>a[i].bj>>a[i].bgb>>a[i].xb>>a[i].lw;
		if(a[i].qm>80 && a[i].lw>=1)
			a[i].ans+=8000;
		if(a[i].qm>85 && a[i].bj>80)
			a[i].ans+=4000;
		if(a[i].qm>90)
			a[i].ans+=2000;
		if(a[i].xb=='Y' && a[i].qm>85)
			a[i].ans+=1000;
		if(a[i].bj>80 && a[i].bgb=='Y')
			a[i].ans+=850;
		a[i].sum=i;
		t+=a[i].ans;
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[1].xm<<endl<<a[1].ans<<endl<<t;
	return 0;
}

