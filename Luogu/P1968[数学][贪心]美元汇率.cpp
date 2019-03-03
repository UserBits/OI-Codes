#include<iostream>
#include<cstdio>
using namespace std;
double max(double x,double y)
{
	return x>y?x:y;
}
int main()
{
	double dollar=100.0,mark=0.0,charge;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>charge;
		dollar=max(dollar,mark/charge);
		mark=max(mark,dollar*charge);
	}
	printf("%.2lf\n",dollar);
	return 0;
}

