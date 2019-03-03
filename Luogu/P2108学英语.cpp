#include <iostream>
#include <string>
using namespace std;
int ans=0,sum=0;
bool p=0;
string s;
void work()
{
	if(s=="negative")
		p=1;
	if(s=="one")
		sum++;
	if(s=="two")
		sum+=2;
	if(s=="three")
		sum+=3;
	if(s=="four")
		sum+=4;
	if(s=="five")
		sum+=5;
	if(s=="six")
		sum+=6;
	if(s=="seven")
		sum+=7;
	if(s=="eight")
		sum+=8;
	if(s=="nine")
		sum+=9;
	if(s=="ten")
		sum+=10;
	if(s=="eleven")
		sum+=11;
	if(s=="twelve")
		sum+=12;
	if(s=="thirteen")
		sum+=13;
	if(s=="fourteen")
		sum+=14;
	if(s=="fifteen")
		sum+=15;
	if(s=="sixteen")
		sum+=16;
	if(s=="seventeen")
		sum+=17;
	if(s=="eighteen")
		sum+=18;
	if(s=="nineteen")
		sum+=19;
	if(s=="twenty")
		sum+=20;
	if(s=="thirty")
		sum+=30;
	if(s=="forty")
		sum+=40;
	if(s=="fifty")
		sum+=50;
	if(s=="sixty")
		sum+=60;
	if(s=="seventy")
		sum+=70;
	if(s=="eighty")
		sum+=80;
	if(s=="ninety")
		sum+=90;
	if(s=="hundred")
		sum*=100;
	if(s=="thousand")
	{
		ans+=sum*1000;
		sum=0;
	}
	if(s=="million")
	{
		ans+=sum*1000000;
		sum=0;
	}
}
int main()
{
	while (cin>>s)
	{
		work();
		s="";
	}
	work();
	ans+=sum;
	if (p==1)
		ans=-ans;
	cout<<ans<<endl;
	return 0;
}

