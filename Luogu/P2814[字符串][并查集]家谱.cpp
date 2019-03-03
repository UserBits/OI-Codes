#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
map<string,string> mp;
string get(string x){
    if(x==mp[x])
        return x;
    return mp[x]=get(mp[x]);
}
int main(){
    char c; string s,t;
    cin>>c;
    while(c!='$'){
        cin>>s;
        if(c=='#'){
            t=s;
            if(mp[s]=="")
                mp[s]=s;
        }
        else if(c=='+')
            mp[s]=t;
        else
            cout<<s<<' '<<get(s)<<endl;
        cin>>c;
    }
    return 0;
}