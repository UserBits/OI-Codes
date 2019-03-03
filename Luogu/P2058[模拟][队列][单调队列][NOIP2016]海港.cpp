#include <cstdio>
using namespace std;
struct node{
    int t,k;
}q[1000005];
int d[100005];
int main(){
    int n,cnt=0,front=1,rear=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t,k,x;
        scanf("%d%d",&t,&k);
        while(k--){
            scanf("%d",&x);
            if(!d[x])
                cnt++;
            q[++rear]=(node){t,x};
            d[x]++;
        }
        while(front<=rear&&t-q[front].t>=86400){
            d[q[front].k]--;
            if(d[q[front].k]==0)
                cnt--;
            front++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}