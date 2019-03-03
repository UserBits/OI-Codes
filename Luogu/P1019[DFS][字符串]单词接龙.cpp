#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
string s[21];
int flag[21];
int sum;
int best;
char c;
void chong(int m)
{
	for(int i=1; i<=2*n; i++)
		if(i!=m&&flag[i]==0)
		{
			int step=min(s[m].size(),s[i].size());
			for(int j=1; j<step; j++)
				if(s[m].substr(s[m].size()-j,j)==s[i].substr(0,j))
				{
					flag[i]=1;
					sum=sum+s[i].size()-j;
					best=max(best,sum);
					chong(i);
					sum=sum-s[i].size()+j;
					flag[i]=0;
				}
		}

}
int main()
{
	cin>>n;
	for(int i=1; i<=n*2; i+=2)
	{
		cin>>s[i];
		s[i+1]=s[i];
	}
	cin>>c;
	for(int i=1; i<=n*2; i++)
		if(s[i][0]==c)
		{
			flag[i]=1;
			sum=sum+s[i].size();
			best=max(best,sum);
			chong(i);
			flag[i]=0;
			sum=sum-s[i].size();
		}
	cout<<best;
	return 0;
}

