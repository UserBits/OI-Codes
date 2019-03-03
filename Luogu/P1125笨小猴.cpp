#include<iostream>
#include<string>
using namespace std;
bool prime(int num)
{
    if(num<2)
        return 0;
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    string s;
    int a[26]={-1},minn=2147483647,maxn=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(a[s[i]-97]==-1)
            a[s[i]-97]==1;
        else
            a[s[i]-97]++;
    }
    for(int i=0;i<26;i++)
    {
        if(a[i]>maxn && a[i]>0)
            maxn=a[i];
        if(a[i]<minn && a[i]>0)
            minn=a[i];
    }
    bool p=prime(maxn-minn);
    if(p==1)
    {
        cout<<"Lucky Word"<<endl;
        cout<<maxn-minn;
    }
    else
        cout<<"No Answer"<<endl<<0;
    return 0;
}
