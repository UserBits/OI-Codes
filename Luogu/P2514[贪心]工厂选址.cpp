#include <cstdio>
#include <algorithm>
using namespace std;
struct Coal{
    int pos,cost;
    friend bool operator < (Coal x,Coal y){
        return x.cost<y.cost;
    }
}t[50005];
int a[50005],c[55][50005],h[50005];
inline void Rd(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    int m,b,n;
    Rd(m);  Rd(b);  Rd(h[0]);   Rd(n);
    for(int i=1;i<=m;i++)
        Rd(a[i]);
    for(int i=1;i<=n;i++)
        Rd(h[i]);
    for(int i=0;i<=n;i++){
        for(int j=1;j<=m;j++)
            Rd(c[i][j]);
    }
    int ans=2e9,factory;
    for(int i=1;i<=n;i++){
        int sum=h[i],tmp=b;
        for(int j=1;j<=m;j++){
            sum+=c[i][j]*a[j];
            t[j].pos=j;
            t[j].cost=c[0][j]-c[i][j];
        }
        sort(t+1,t+1+m);
        for(int j=1;j<=m && tmp;j++){
            if(tmp>=a[t[j].pos]){
                sum+=t[j].cost*a[t[j].pos];
                tmp-=a[t[j].pos];
            }
            else{
                sum+=tmp*t[j].cost;
                break;
            }
        }
        if(sum<ans){
            ans=sum;
            factory=i;
        }
    }
    printf("%d\n%d\n",factory,ans+h[0]);
    return 0;
}