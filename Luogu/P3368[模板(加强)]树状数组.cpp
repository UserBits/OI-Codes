#include <cstdio>
#include <cstdlib>
int a[500005],n;
inline int lowbit(int x){
    return x&(-x);
}
inline void qr(int &s){
    s=0;
    bool f=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar()){
        if(c=='-')
            f=1;
    }
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
    if(f)
        s=-s;
}
inline void update(int x,int y){
    while(x<=n){
        a[x]+=y;
        x+=lowbit(x);
    }
}
inline int query(int x){
    int ans=0;
    while(x){
        ans+=a[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    int m,x=0,y,k;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        qr(y);
        update(i,y-x);
        x=y;
    }
    while(m--){
        qr(k);
        if(k==1){
            qr(x);  qr(y);  qr(k);
            update(x,k);
            update(y+1,-k);
        }
        else{
            qr(x);
            printf("%d\n",query(x));
        }
    }
    return 0;
}