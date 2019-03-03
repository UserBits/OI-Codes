#include<iostream>
#include<string>
using namespace std;
int main()
{
    string isbncode;
    int mathcode[13]={0},realcode=0;
    int mycode=0;
    cin>>isbncode;
    for(int i=0;i<=12;i++)
        mathcode[i]=isbncode[i]-'0';
    mycode=mathcode[0]*1+mathcode[2]*2+mathcode[3]*3+mathcode[4]*4+mathcode[6]*5+mathcode[7]*6+mathcode[8]*7+mathcode[9]*8+mathcode[10]*9;
    mycode=mycode%11;
    if(mycode==10)
        mycode='X'-'0';
    if(mycode==mathcode[12])
        cout<<"Right";
    else
        cout<<mathcode[0]<<'-'<<mathcode[2]<<mathcode[3]<<mathcode[4]<<'-'<<mathcode[6]<<mathcode[7]<<mathcode[8]<<mathcode[9]<<mathcode[10]<<'-'<<char(mycode+'0');
    return 0;
}
