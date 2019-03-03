#include <cstdio>
const int mod=20123;
inline void qr(int &s){
    s=0;
    register char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+(c-'0');
}
int a[10001][101],b[10001][101],sum[10001];
//sum[i]记录第i层的楼梯数量总和
int main(){
    int n,m,i,j;
    qr(n);  qr(m);
    for(i=1;i<=n;++i){
        for(j=0;j<m;++j){
            qr(a[i][j]);    qr(b[i][j]);
            sum[i]+=a[i][j];
        }
    }
    int dep=1,loc,ans=0,tmp,cnt;
    //表示当前在第dep层编号为loc的房间
    //注: loc从0~m-1
    qr(loc);
    while(dep<=n){
        ans+=b[dep][loc];
        ans%=mod;
        tmp=b[dep][loc];
        tmp=(tmp-1)%sum[dep]+1;
        //减一: 当前位置本身就有楼梯
        //加一: 将序号转换为个数
        cnt=0; //已经经过的、有楼梯的房间个数
        while(cnt<tmp){
            cnt+=a[dep][loc];
            if(cnt==tmp)
                break;
            ++loc;
            if(loc==m)
                loc=0;
        }
        ++dep;
    }
    printf("%d",ans);
    return 0;
}