#include<iostream>
using namespace std;
int main()
{
    int n,x,p=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        int s=i;
        while(s!=0)
        {
            if(s%10==x)
                p++;
            s/=10;
        }
    }
    cout<<p<<endl;
    return 0;
}
