#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
    int a,b,x,y,s;
    char m,n;
    cin>>a>>m>>b;
    cin>>x>>n>>y;
    x*=a;
	y*=b;
	s=gcd(x,y);
    x/=s;
	y/=s;
    cout<<y<<" "<<x;
    return 0;
}

