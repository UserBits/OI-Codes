#include<string>
#include<iostream>
using namespace std;
string a,c;
int main()
{
	int b=0,d=0;
    cin>>a>>b;
	int len=a.length();
    for (int i=0;i<len;i++)
		a[i]-=48;
    for (int i=0;i<len;i++)
	{
        c.push_back((d*10+a[i])/b+48);
		d=(d*10+a[i])%b;
	}
    for (int i=0;c[0]==48;i++)
		c.erase(c.begin(),c.begin()+1);
    cout<<c;
    return 0;
}

