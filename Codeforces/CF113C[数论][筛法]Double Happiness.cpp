#include <cstdio>
#include <cstdlib>
#include <bitset>
using namespace std;
bitset<300000005> np;
int s,p[20000005];
void pre(int r){
    for(int i=2;i<=r;i++){
        if(!np[i])
            p[++s]=i;
        for(int j=1;j<=s && i*p[j]<=r;j++){
            np[i*p[j]]=1;
            if(i%p[j]==0)
                break;
        }
    }
}
int main(){
    int l,r;
    scanf("%d%d",&l,&r);
    int ans=0;
    pre(r);
    for(int i=1;i<=s;i++){
        if(p[i]<l)
            continue;
        if(p[i]%4==1)
            ans++;
    }
    if(l<=2 && r>=2)
        ans++;
    printf("%d\n",ans);
    return 0;
}