#include <cstdio>
#include <iostream>
#include <cstdlib>
using std::cin;
int c[500005],n;
inline int lowbit(int x){
    return x&(-x);
}
inline void qr(int &s){
    s=0;
    char c=getchar();
    int f=1;
    for(;c<'0'||c>'9';c=getchar()){
        if(c=='-')
            f=-1;
    }
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
    s*=f;
}
void update(int x,int y){
    while(x<=n){
        c[x]+=y;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    int m,x,y;
    char k;
    qr(n);  qr(m);
    while(m--){
        cin>>k;  qr(x);  qr(y);
        if(k=='x')
            update(x,y);
        else
            printf("%d\n",sum(y)-sum(x-1));
    }
}