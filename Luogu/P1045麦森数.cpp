#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
struct BigNum{
    int a[505],len;
    BigNum(){
        memset(a,0,sizeof(a));
        len=1;
    }
};
BigNum multi(BigNum x,BigNum y){
    BigNum ans;
    ans.len=500;
    for(int i=1;i<=x.len;i++){
        for(int j=1;j<=y.len;j++){
            if(i+j-1<=500)
                ans.a[i+j-1]+=x.a[i]*y.a[j];
        }
    }
    for(int i=1;i<=ans.len;i++){
        ans.a[i+1]+=ans.a[i]/10;
        ans.a[i]%=10;
    }
    while(ans.a[ans.len]==0 && ans.len>1)
        ans.len--;
    return ans;
}
BigNum q_pow(int y){
    BigNum x,r;
    x.a[1]=2;
    r.a[1]=1;
    while(y){
        if(y&1)
            r=multi(r,x);
        x=multi(x,x);
        y>>=1;
    }
    return r;
}
int main(){
    int x;
    scanf("%d",&x);
    BigNum res=q_pow(x);
    res.a[1]--;
    printf("%d\n",(int)(log10(2)*x+1));
    int cnt=0;
    for(int i=500;i>0;i--){
        putchar(res.a[i]+'0');
        cnt++;
        if(cnt==50){
            cnt=0;
            putchar('\n');
        }
    }
    puts("");
    //system("pause");
    return 0;
}
