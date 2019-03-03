#include <cstdio>
#include <iostream>
using namespace std;
int len;
char a[50005];
void init()
{
	int i;
	i=0;
	do
	{
		i++;
		cin>>a[i];
	}
	while(a[i]!='E');
	len=i-1;
}
void out(int x)
{
	int i,w=0,l=0;
	for(i=1; i<=len; i++)
	{
		if (a[i]=='W')
			w++;
		if (a[i]=='L')
			l++;
		if((w>=x && w-l>1)||(l>=x && l-w>1))
		{
			printf("%d:%d\n",w,l);
			w=0;
			l=0;
		}
	}
	printf("%d:%d\n",w,l);
}
int main()
{
	init();
	out(11);
	printf("\n");
	out(21);
	return 0;
}
