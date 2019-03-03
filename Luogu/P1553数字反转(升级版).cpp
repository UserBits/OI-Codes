#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[25];
int main()
{
	scanf("%s",a);
	int len=strlen(a),mid;
	bool point=0,percent=0,pernum=0;
	for(int i=0;i<len;i++)
	{
		if(a[i]=='.')
		{
			point=1;
			mid=i;
			break;
		}
		if(a[i]=='/')
		{
			pernum=1;
			mid=i;
			break;
		}
		if(a[i]=='%')
		{
			percent=1;
			break;
		}
	}
	if(!percent && !pernum && !point)
	{
		bool p=0;
		for(int i=len-1;i>=0;i--)
		{
			if(a[i]!='0')
				p=1;
			if(p==1)
				printf("%c",a[i]);
		}
		if(p==0)
			printf("0");
		return 0;
	}
	if(percent==1)
	{
		bool p=0;
		for(int i=len-2;i>=0;i--)
		{
			if(a[i]!='0')
				p=1;
			if(p==1)
				printf("%c",a[i]);
		}
		if(p==0)
			printf("0");
		printf("%%");
		return 0;
	}
	if(point==1 || pernum==1)
	{
		bool p=0;
		for(int i=mid-1;i>=0;i--)
		{
			if(a[i]!='0')
				p=1;
			if(p==1)
				printf("%c",a[i]);
		}
		if(p==0)
			printf("0");
		if(point==1)
			printf(".");
		else if(pernum==1)
			printf("/");
		p=0;
		//printf("%d %d\n",len,mid);
		while(a[mid+1]=='0')
			mid++;
		if(pernum)
		{
			for(int i=len-1;i>mid;i--)
			{
				if(a[i]!='0')
					p=1;
				if(p==1)
					printf("%c",a[i]);
			}
			return 0;
		}
		for(int i=len-1;i>mid;i--)
		{
			printf("%c",a[i]);
			p=1;
		}
		if(p==0 && point)
			printf("0");
		return 0;
	}
	return 0;
}
