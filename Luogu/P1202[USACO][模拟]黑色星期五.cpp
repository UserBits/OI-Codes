#include<iostream>
#include<cstdio>
using namespace std;
int a[7];
int day(int x,int y)
{
	switch(y)
	{
		case 1: case 2: case 4: case 6: case 8: case 9: case 11: return 31;
		case 5: case 7: case 10: case 12: return 30;
		case 3: if(!(x%4) && (x%100) || !(x%400)) return 29;
				else return 28;
	}
}
int main()
{
	int s=3,n;
	scanf("%d",&n);
	for(int i=1900;i<n+1900;i++)
	{
		for(int j=1;j<13;j++)
		{
			s=(s+day(i,j))%7;
			a[s]++;
		}
	}
	printf("%d ",a[6]);
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
