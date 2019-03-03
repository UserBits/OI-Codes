#include<iostream>
#include<string>
using namespace std;
string gs[21],ll;
int n,m,ans=0;
int main()
{
	cin>>n>>m;
	getline(cin,ll);
	for(int i=1; i<=n; i++)
		getline(cin,gs[i]);
	for(int i=1; i<=m; i++)
	{
		getline(cin,ll);
		if(ll[ll.size()-1]!=13)ll=ll+(char)13;
		for(int j=1; j<=n; j++){
			if(ll==gs[j])
			{
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
