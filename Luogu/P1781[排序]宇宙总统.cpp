#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,Max_=-1;
    string a,max_="0";
    cin>>n;
    for(int k=1;k<=n;k++)
    {
        cin>>a;
        if(a.length()>max_.length())
        {
            max_=a;
            Max_=k;
        }
        if((a.length()==max_.length()) && (a>max_))
        {
            max_=a;
            Max_=k;
        }
    }
    cout<<Max_<<endl<<max_;
    return 0;
}
