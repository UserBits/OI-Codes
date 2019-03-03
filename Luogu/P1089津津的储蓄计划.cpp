#include<iostream>
using namespace std;
int main()
{
    int i,hand=0,n=0,money,bank=0,m=0;
    for(i=1;i<=12;i++)
    {
        hand+=300;
        cin>>money;
        hand-=money;
        if(n==0 && hand<0)
        {
            m=i;
            n++;
        }
        if(hand>100)
        {
            bank+=hand/100*100;
            hand%=100;
        }
    }
    if(m==0)
        cout<<1.0*hand+bank*1.2<<endl;
    else
        cout<<-m<<endl;
    return 0;
}
