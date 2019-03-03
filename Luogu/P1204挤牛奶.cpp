#include<iostream>
using namespace std;
bool milk[1000005];
int main()
{
    int n, first=1000000,last=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int star,end;
        cin>>star>>end;
        for(int j=star;j<end;j++)
            milk[j]=1;
        if(star<first)
            first=star;
        if(end>last)
            last=end;
    }
    int sum=0,ans1=0,num=0,ans2=0;
    for(int i=first;i<=last;i++)
    {
        if(milk[i] == 1)
        {
            if(num>ans2)
                ans2=num;
            num=0;
            sum++;
        }
        else
        {
            if(sum>ans1)
                ans1=sum;
            sum=0;
            num++;
        }
    }
    cout<<ans1<<" "<<ans2<<"\n";
    return 0;
}

