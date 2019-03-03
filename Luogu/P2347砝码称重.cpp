#include<iostream>
using namespace std;
bool p[1005];
int main()
{
	int x[6],s,total=0;
	for(int i=0;i<6;i++)
		cin>>x[i];
	for(int a=0;a<=x[0];a++)
	{
		for(int b=0;b<=x[1];b++)
		{
			for(int c=0;c<=x[2];c++)
			{
				for(int d=0;d<=x[3];d++)
				{
					for(int e=0;e<=x[4];e++)
					{
						for(int f=0;f<=x[5];f++)
						{
							s=a+b*2+c*3+d*5+e*10+f*20;
							p[s]=1;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<1001;i++)
	{
		if(p[i])
			total++;
	}
	cout<<"Total="<<total<<endl;
	return 0;
}
