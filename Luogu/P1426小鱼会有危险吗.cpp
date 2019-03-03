#include<iostream>
using namespace std;
int main()
{
	double sum=0.0,et=7.0;
	int s,x;
	cin>>s>>x;
	int left=s-x,right=s+x;
	while(sum<left)
	{
		sum+=et;
		et*=0.98;
	}
	if(sum+et>right)
		cout<<'n'<<endl;
	else
		cout<<'y'<<endl;
	return 0;
}
