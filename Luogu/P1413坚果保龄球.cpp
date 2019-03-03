#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
	vector<int> t;
}a[10];
int main()
{
	int n,x,y;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		a[x].t.push_back(y);
	}
	for(int i=1;i<=6;i++)
		sort(a[i].t.begin(),a[i].t.end());
	int ans=0,maxn,tmp;
	for(int i=1;i<=6;i++)
	{
		maxn=a[i].t.size();
		if(maxn>0)
		{
			ans++;
			tmp=0;
			for(int j=1;j<maxn;j++)
			{
				if(a[i].t[j]-a[i].t[tmp]>=60)
				{
					ans++;
					tmp=j;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

