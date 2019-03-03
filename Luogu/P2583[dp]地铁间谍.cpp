#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int meet[205],left[205],right[205],f[205][55];
bool train[2][205][10005];
/*
    train[i][j][k]表示(i==0: 从第1站到第n站方向；i==1: 从第n站到第1站方向)
    在第k秒时候能否在第j个站
*/
//f[i][j]表示在第i秒时候到第j个站所需最少等待时间
const int INF=1<<30;
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main()
{
    for(int i=1;;i++){
        int n,t,m1,m2;
        qr(n);
        if(!n)
            break;
        memset(train,0,sizeof(train));
        memset(f,0,sizeof(f));
        qr(t);
        for(int i=1;i<n;i++)
            qr(meet[i]);
        qr(m1);
        int sum;
        for(int i=1;i<=m1;i++){
            qr(left[i]);
            sum=left[i];
            for(int j=1;j<=n;j++){
                train[0][j][sum]=1;
                sum+=meet[j]; //枚举每个站为起点，初始化
            }
        }
        qr(m2);
        for(int i=1;i<=m2;i++){
            qr(right[i]);
            sum=right[i];
            for(int j=n;j>0;j--){  
                train[1][j][sum]=1;
                sum+=meet[j-1];
            }
        }
        for(int i=1;i<n;i++)
            f[t][i]=INF;
        f[t][n]=0;
        for(int i=t-1;i>=0;i--){
            //枚举在该时刻之前能到达本站的所有站点
            for(int j=1;j<=n;j++){
                f[i][j]=f[i+1][j]+1;
                //在本站再次等待1个单位的时间
                //排除起点、终点的情况
                if(j<n && train[0][j][i] && i+meet[j]<=t)
                    f[i][j]=min(f[i][j],f[i+meet[j]][j+1]);
                if(j>1 && train[1][j][i] && i+meet[j-1]<=t)
                    f[i][j]=min(f[i][j],f[i+meet[j-1]][j-1]);
            }
        }
        if(f[0][1]<INF)
            printf("Case Number %d: %d\n",i,f[0][1]);
        else
            printf("Case Number %d: impossible\n",i);
    }
    return 0;
}
