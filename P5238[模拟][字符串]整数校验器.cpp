#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct bignum{
    int len; 
    char a[10000];
    bool negative;
    bignum(){
        memset(a,0,sizeof(a));
        len=1;
        negative=0;
    }
    void output(){
        putchar('[');
        if(negative)
            putchar('-');
        for(int i=1;i<=len;i++)
            putchar(a[i]);
        puts("]");
    }
};
char compare(bignum x,bignum y){
    if(x.negative && !y.negative)
        return '<';
    if(!x.negative && y.negative)
        return '>';
    if(x.len<y.len){
        if(x.negative)
            return '>';
        return '<';
    }
    if(x.len>y.len){
        if(x.negative)
            return '<';
        return '>';
    }
    for(int i=1;i<=x.len;i++){
        if(x.a[i]<y.a[i]){
            if(x.negative)
                return '>';
            return '<';
        }
        if(x.a[i]>y.a[i]){
            if(x.negative)
                return '<';
            return '>';
        }
    }
    return '=';
}

char k[10000];
void convert(bignum &x){
    if(k[0]=='-'){
        x.negative=1;
        strcpy(x.a,k);
        x.len=strlen(k+1);
    }
    else{
        x.negative=0;
        strcpy(x.a+1,k);
        x.len=strlen(k);
    }
    memset(k,0,sizeof(k));
}

int main(){
    int t; bignum l,r,x;
    cin>>k; convert(l);
    cin>>k; convert(r);
    cin>>t;
    while(t--){
        cin>>k; convert(x);
        //x.output();
        if(!x.negative && x.len==1 && x.a[1]=='0');
        else{
            if(x.a[1]>='1' && x.a[1]<='9');
            else{
                puts("1");
                continue;
            }
            bool flag=0;
            for(int i=2;i<=x.len;i++){
                if(x.a[1]<'0' || x.a[1]>'9'){
                    flag=1;
                    puts("1");
                    break;
                }
            }
            if(flag)
                continue;
        }
        if(compare(l,x)=='>' || compare(r,x)=='<')
            puts("2");
        else
            puts("0");
    }
    //system("pause");
    return 0;
}