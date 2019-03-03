#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int n=s.size(),ans=0;
    for(int i=0;i<n;i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z'))
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}