#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int x[100005],a[200005];
const int val=100001;
int main(){
    int n,p,mid,pos;
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&mid);
        for(int i=1;i<=n;i++){
            scanf("%d",&p);
            if(p==mid)
                x[i]=0,pos=i;
            if(p<mid)
                x[i]=-1;
            if(p>mid)
                x[i]=1;
        }
        long long ans=0;
        int sum=0;
        a[val]=1;
        for(int i=1;i<pos;i++){
            sum+=x[i];
            a[sum+val]++;
        }
        for(int i=pos;i<=n;i++){
            sum+=x[i];
            ans+=a[val+sum];
        }
        cout<<ans<<endl;
    return 0;
}
