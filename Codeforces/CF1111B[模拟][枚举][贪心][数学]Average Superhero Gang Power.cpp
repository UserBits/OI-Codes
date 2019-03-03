/*
给出n,k,m和n个数，表示每个人的能力值。
进行m次操作，每次操作可以删掉一个人（至少有两个人时）
或者给一个人的能力值+1，且每个人能力值加的次数不能超过k。
问最后所有剩下的人的能力值的平均的最大值。
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
int a[200005];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n); //先删除小的
    long double sum=0,ans=0;
    for(long long i=n-1;i>=0;i--){ //枚举删的人数（至少留1人）
        sum+=a[i+1];
        if(i<=m){
            long double tmp=sum+min(m-i,(n-i)*k); 
            //看是能对m个人加上1，还是能直接给每个人加满
            ans=max(ans,tmp/(n-i));
        }
    }
    cout<<fixed<<setprecision(15)<<ans<<endl;
    return 0;
}