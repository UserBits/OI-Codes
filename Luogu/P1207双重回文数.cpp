#include<iostream>
#include<cstring>
using namespace std;
bool check(int a)
{
	int c=0,str[99];
	for(int base=2; base<=10; base++)
	{
		int A=a,poi=1,f=0;
		memset(str,0,sizeof(str));
		while(A)
		{
			str[poi++]=A%base;
			A/=base;
		}
		for(int i=1; i<poi; i++)if(str[i]-str[poi-i])f++;
		if(!f)c++;
	}
	return c>1;
}
int main()
{
	int n,s;
	cin>>s>>n;
	int i=n+1;
	while(s)for(;; i++)if(check(i))
			{
				cout<<i++<<endl;
				s--;
				break;
			}
}
