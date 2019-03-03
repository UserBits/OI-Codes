#include<iostream>
using namespace std;
int main()
{
    int n[10],h,s=0;
    for(int i=0;i<10;i++)
        cin>>n[i];
    cin>>h;
    h+=30;
    for(int i=0;i<10;i++)
    {
        if(n[i]<=h)
            s++;
    }
    cout<<s<<endl;
    return 0;
}
