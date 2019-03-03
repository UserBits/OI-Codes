#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
inline void qr(int &s){
    s=0;
    bool flag=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar()){
        if(c=='-')
            flag=1;
    }
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
    if(flag)
        s=-s;
}
const int N=1000005;
int l[N],r[N],v[N],cnt[N],ans=1;
bool check(int x,int y){
    if(x==-1 && y==-1)
        return 1;
    if(x==-1 || y==-1)
        return 0;
    if(cnt[x]!=cnt[y] || v[x]!=v[y])
        return 0;
    return check(l[x],r[y])&&check(r[x],l[y]);
}
void dfs(int x){
    cnt[x]=1;
    if(l[x]!=-1){
        dfs(l[x]);
        cnt[x]+=cnt[l[x]];
    }
    if(r[x]!=-1){
        dfs(r[x]);
        cnt[x]+=cnt[r[x]];
    }
    if(check(l[x],r[x]))
        ans=max(ans,cnt[x]);
}
int main(){
    int n;
    qr(n);
    for(int i=1;i<=n;i++)
        qr(v[i]);
    for(int i=1;i<=n;i++){
        qr(l[i]);   qr(r[i]);
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}