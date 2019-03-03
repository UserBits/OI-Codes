#include<iostream>
using namespace std;
int main()
{
	int k,i;
	double sum=0.0;
	cin>>k;
	for(i=1;sum<=k*1.0;i++)
		sum+=1.0/i;
	cout<<--i<<endl;
	return 0;
}
