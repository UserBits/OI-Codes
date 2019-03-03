#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	int day;
	scanf("%d",&day);
	int no=0,yes=0,ans=0,p;
	for(int i=0;i<day;i++)
	{
		scanf("%d",&p);
		if(p==1)
		{
			if(no>0)
				yes-=pow(2,no-1);
			if(yes<0)
				yes=0;
			yes++;
			ans++;
			no=0;
			if(yes>=3)
				ans++;
			if(yes>=7)
				ans++;
			if(yes>=30)
				ans++;
			if(yes>=120)
				ans++;
			if(yes>=365)
				ans++;
		}
		else if(p==0)
			no++;
	}
	printf("%d\n",ans);
	return 0;
}
