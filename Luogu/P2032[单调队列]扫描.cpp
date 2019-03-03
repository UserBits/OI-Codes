#include <cstdio>
#include <cstdlib>
const int N=2000005;
int a[N];
struct node{
    int x,y;
}q[N];
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        qr(a[i]);
    int head=1,tail=0,i;
    for(i=1;i<k;i++){
        while(head<=tail && q[tail].x<=a[i])
            tail--;
        q[++tail].x=a[i];
        q[tail].y=i;
    }
    for(;i<=n;i++){
        while(head<=tail && q[tail].x<=a[i])
            tail--;
        q[++tail].x=a[i];
        q[tail].y=i;
        while(q[head].y<i-k+1)
            head++;
        printf("%d\n",q[head].x);
    }
    return 0;
}