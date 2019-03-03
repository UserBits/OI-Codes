#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
int main()
{
    cin>>a>>b>>c>>d;
    for(double i=-100.00;i<=100.00;i+=0.01)
    {
        if(a*i*i*i+b*i*i+c*i+d<0.00000001&&a*i*i*i+b*i*i+c*i+d>-0.00000001)
            printf("%.2lf ",i);

    }
    return 0;
}

