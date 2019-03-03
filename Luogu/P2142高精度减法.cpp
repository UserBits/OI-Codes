#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int a[20005],b[20005],ans[20005],cs,len1,len2,j;
string s1,s2;
int main()
{
	cin>>s1>>s2;
	if(s1==s2)
	{
		printf("0\n");
		return 0;
	}
	len1=s1.size();
	len2=s2.size();
	if((len1<len2) || ((len1==len2) && (s1<s2)))
	{
		swap(s1,s2);
		swap(len1,len2);
		printf("-");
	}
	for(int i=0;i<len1;i++)
		a[len1-i-1]=s1[i]-'0';
	for(int i=0;i<len2;i++)
		b[len2-i-1]=s2[i]-'0';
	cs=max(len1,len2);
	for(int i=0;i<cs;i++)
	{
		if(a[i]-b[i]<0)
		{
			a[i+1]--;
			a[i]+=10;
		}
		ans[i]=a[i]-b[i];
	}
	for(j=cs-1;j>=0;j--)
	{
		if(ans[j]!=0)
			break;
	}
	for(;j>=0;j--)
	{
		if(ans[j]>=0 && ans[j]<=9)
			printf("%d",ans[j]);
	}
	return 0;
}

