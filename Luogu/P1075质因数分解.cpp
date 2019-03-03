#include<iostream>
using namespace std;
int main()
{
    int n,a;
    cin>>n;
    for(a=2;n%a!=0;a++);
    cout<<n/a<<endl;
    return 0;
}
