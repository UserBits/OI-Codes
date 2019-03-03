#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	int len[5],max;
	cin>>len[0]>>len[1]>>len[2];
	sort(len,len+3);
	max=gcd(len[0],len[2]);
	cout<<len[0]/max<<'/'<<len[2]/max<<endl;
	return 0;
}
