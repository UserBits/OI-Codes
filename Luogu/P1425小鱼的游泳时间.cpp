#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b;
    cin>>c>>d;
    if(d<b)
    {
        d+=60;
        c--;
    }
    e=c-a;
    f=d-b;
    cout<<e<<' '<<f<<endl;
    return 0;
}
