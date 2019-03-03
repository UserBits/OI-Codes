#include<iostream>
using namespace std;
int main()
{
    int l,r,temp,s=0;
    cin>>l>>r;
    if(l>r)
    {
        temp=l;
        l=r;
        r=temp;
    }
    for(l;l<=r;l++)
    {
        temp=l;
        while(temp!=0)
        {
            if(temp%10==2)
                s++;
            temp/=10;
        }
    }
    cout<<s<<endl;
    return 0;
}
