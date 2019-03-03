#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[310];
int main()
{
	int s,len,i,j,k;
	bool flag=0;
	scanf("%s%d",a,&s);
	len=strlen(a);
	for(i=1;i<=s;i++)
	{
		for(j=0;j<len;j++)
		{
			if(a[j]>a[j+1])
			{
				for(k=j;k<len;k++)
					a[k]=a[k+1];
				break;
			}
		}
		len--;
	}
	for(i=0;i<len;i++)
	{
		if(a[i]!='0' || i==len-1)
			flag=1;
		if(flag)
			printf("%c",a[i]);
	}
	return 0;
}

