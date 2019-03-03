#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
string add(string a_str, string b_str)
{
    int a[a_str.length()], b[b_str.length()];
    for (int i=0; i<a_str.length(); i++) a[i] = a_str[a_str.length()-1-i] - '0';
    for (int i=0; i<b_str.length(); i++) b[i] = b_str[b_str.length()-1-i] - '0';
    int maxSize = max(a_str.length(), b_str.length())+1;
    int c[maxSize];
    for (int i=0; i<maxSize; i++)
        c[i] = 0;
    for (int i=0; i<maxSize; i++)
    {
        if (i<a_str.length() && i<b_str.length())
            c[i] += a[i] + b[i];
        else if (i>=a_str.length() && i<b_str.length())
            c[i] += b[i];
        else if (i<a_str.length() && i>=b_str.length())
            c[i] += a[i];
        if (c[i]>=10)
        {
            c[i+1]++;
            c[i] %= 10;
        }
    }
    ostringstream oss;
    for (int i=0; i<maxSize; i++)
        oss<<c[maxSize-1-i];
    string s = oss.str();
    while (s[0]=='0' && s.length()>1) s.erase(0, 1);
    return s;
}
int main()
{
    int n;
    cin>>n;
    if (n == 0) cout<<"0"<<endl;
    else if (n == 1) cout<<"1"<<endl;
    else if (n == 2) cout<<"2"<<endl;
    else
    {
        string a[n+1];
        a[1] = "1";
        a[2] = "2";
        for (int i=3; i<=n; i++)
            a[i] = add(a[i-1], a[i-2]);
        cout<<a[n]<<endl;
    }
    return 0;
}
