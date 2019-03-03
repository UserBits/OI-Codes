#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[101],b[101],c[101],d[26],e[101];
    int count=0;
    cin>>a;
    cin>>b;
    int h=strlen(b);
    cin>>c;
    for(int i=0;i<h;i++)
        d[a[i]-'A']=b[i];
    int k=strlen(c);
    for(int i=0;i<26;i++){
        for(int j=i+1;j<26;j++){
            if(b[a[i]-'A']==b[a[j]-'A']&&a[i]!=a[j]){
                cout<<"Failed"<<endl;
                return 0;
            }
            else if(d[i]=='\0')
           {
                cout<<"Failed"<<endl;
                return 0;
            }
        }
    }
    for(int i=0;i<k;i++){
        if(d[c[i]-'A'])
        e[i]=d[c[i]-'A'];
        cout<<e[i];
    }
    return 0;
}
