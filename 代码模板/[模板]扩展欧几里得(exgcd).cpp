#include <cstdio>
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return d;
}