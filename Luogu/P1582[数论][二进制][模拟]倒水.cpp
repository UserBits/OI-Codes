#include <cstdio>
#include <algorithm>
using namespace std;
int t[50];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int len=0,tmp=n,one=0;
    while(tmp){
        t[++len]=tmp&1;
        if(t[len])
            one++;
        tmp>>=1;
    }
    if(one<=k){
        puts("0");
        return 0;
    }
    //printf("%d\n",one);
    long long ans=0;
    for(int i=1;one>k;i++){
        if(t[i]>1){
            t[i]=0;
            t[i+1]++;
            one--;
        }
        if(t[i]){
            ans+=(1<<i-1);
            t[i+1]++;
        }
    }
    printf("%lld\n",ans);
    //system("pause");
    return 0;
}
