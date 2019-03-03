#include <cstdio>
#include <cstdlib>
using namespace std;
const int N=70000;
int p[20005];
bool np[N],res[1000005];
inline int pre(){
    int s=0;
    for(int i=2;i<N;i++){
        if(!np[i])
            p[++s]=i;
        for(int j=1;j<=s && i*p[j]<=N;j++){
            np[i*p[j]]=1;
            if(i%p[j]==0)
                break;
        }
    }
    return s;
}
int main(){
    int len=pre();
    long long l,r;
    scanf("%lld%lld",&l,&r);
    if(l==1)
        l++;
    for(int i=1;i<=len;i++){
        long long tmp=(l+p[i]-1)/p[i]*p[i];
        if(tmp==p[i])
            tmp<<=1;
        for(long long j=tmp;j<=r;j+=p[i]){
            if(j!=p[i])
                res[j-l]=1;
        }
    }
    int ans=0;
    for(long long i=l;i<=r;i++)
        ans+=(!res[i-l]);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}