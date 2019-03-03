#include<iostream>
#include<string>
using namespace std;
struct peo
{
	string name;
	int money;
}a[25];
int min(int p,int q)
{
	return p<q?p:q;
}
bool cmp(string a,string b)
{
	int x=a.size(),y=b.size();
	int len=min(x,y);
	if(x!=y)
		return 0;
	for(int i=0;i<len;i++)
	{
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}
int main()
{
	//freopen("program.in","r",stdin);
	//freopen("program.out","w",stdout);
	int n;
	cin>>n;
	string tmp;
	for(int i=1;i<=n;i++)
		cin>>a[i].name;//cout<<'['<<a[i].name<<']'<<endl;
	int r,s;
	int p;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		//cout<<'['<<tmp<<']'<<endl;
		cin>>r>>s;
		for(int j=1;j<=n;j++)
		{
			if(cmp(a[j].name,tmp)==1)
				p=j;
		}
		//cout<<'('<<p<<')'<<endl;
		for(int j=1;j<=s;j++)
		{
			string edit;
			cin>>edit;
			//cout<<'['<<edit<<']'<<endl;
			//cout<<'#'<<r<<','<<s<<'#'<<endl;
			for(int k=1;k<=n;k++)
			{
				if(cmp(a[k].name,edit)==1)
				{
					a[k].money+=r/s;
					a[p].money-=r/s;
					//cout<<'{'<<a[k].money<<','<<a[p].money<<'}'<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i].name<<' '<<a[i].money<<endl;
	return 0;
}

