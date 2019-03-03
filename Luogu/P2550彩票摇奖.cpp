#include<iostream>
#include<cstdio>
using namespace std;
int need[10],buy[10],ans[10];
int work()
{
	int s=0;
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(need[i]==buy[j])
				s++;
		}
	}
	return s;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<7;i++)
		scanf("%d",&need[i]);
	while(n--)
	{
		for(int i=0;i<7;i++)
			scanf("%d",&buy[i]);
		switch(work())
		{
			case 7: ans[0]++; break;
			case 6: ans[1]++; break;
			case 5: ans[2]++; break;
			case 4: ans[3]++; break;
			case 3: ans[4]++; break;
			case 2: ans[5]++; break;
			case 1: ans[6]++; break;
			default: break;
		}
	}
	for(int i=0;i<7;i++)
		printf("%d ",ans[i]);
	return 0;
}

