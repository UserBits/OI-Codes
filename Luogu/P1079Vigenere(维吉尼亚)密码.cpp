#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char k[1005],n[1005];
int a[1005];
int main()
{
	cin>>k>>n;
	int lk=strlen(k),ln=strlen(n);
	for(int i=0;i<lk;i++)
	{
		if(k[i]>='a' && k[i]<='z')
			a[i]=k[i]-'a';
		else
			a[i]=k[i]-'A';
	}
	for(int i=0;i<ln;i++)
	{
		//printf("[%d]\n",a[i%lk]);
		if(n[i]>='A' && n[i]<='Z')
		{
			n[i]=n[i]-a[i%lk];
			if(n[i]<'A')
				n[i]='Z'-('A'-n[i])+1;
		}
		else
		{
			n[i]=n[i]-a[i%lk];
			if(n[i]<'a')
				n[i]='z'-('a'-n[i])+1;
		}
		//printf("%c\n",n[i]);
	}
	for(int i=0;i<ln;i++)
		printf("%c",n[i]);
	return 0;
}
