#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
string s[5005];
char p[10][4]={{},{},"ABC","DEF","GHI","JKL","NMO","PRS","TUV","WXY"};
int main(){
    int n=0,tmp;
    while(cin>>s[n++]);
    string x=s[0];
    for(int i=0;i<x.size();i++)
        x[i]-='0';
    n--;
    bool found=0,flag;
    for(int i=1;i<=n;i++){
        if(s[i].size()!=x.size())
            continue;
        flag=1;
        tmp=s[i].size();
        for(int j=0;j<tmp;j++)
            flag=flag && (s[i][j]==p[x[j]][0] || s[i][j]==p[x[j]][1] || s[i][j]==p[x[j]][2]);
        if(flag){
            found=1;
            cout<<s[i]<<endl;
        }
    }
    if(!found)
        cout<<"NONE"<<endl;
    return 0;
}