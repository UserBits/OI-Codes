#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[20];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int ans=0,len=strlen(s);
		for(int i=0;i<len;i++)
			ans=ans*9+s[i]-'0'-(s[i]>'7'?1:0);
		printf("%d\n",ans);
	}
	return 0;
}
