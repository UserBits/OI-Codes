#include <cstdio>
#include <cstdlib>
int sum[55],cnt[55],last[55];
//last[i]最后一个颜色为i的客栈的序号
//cnt[i]颜色为i的客栈的数量
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    int n,k,p,colour,price,tmp=0,ans=0;
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++){
        qr(colour);
        qr(price);
        if(price<=p)
            tmp=i;
        if(tmp>=last[colour])
            sum[colour]=cnt[colour];
        last[colour]=i;
        ans+=sum[colour];
        cnt[colour]++;
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}