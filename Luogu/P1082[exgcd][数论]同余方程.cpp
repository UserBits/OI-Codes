#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return d;
}
int main(){
    ll a,b,x,y;
    cin>>a>>b;
    exgcd(a,b,x,y);
    ll r=(x%b+b)%b;
    cout<<r<<endl;
    return 0;
}