#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
bool np[1000005];
int p[1000005],sum[1000005];
void work(){
    int s=0;
    for(int i=2;i<1000005;i++){
        if(!np[i])
            p[++s]=i;
        for(int j=1;p[j]*i<=1000000 && j<=s;j++){
            np[p[j]*i]=1;
            if(i%p[j]==0)
                break;
        }
    }
}
int main(){
    work();
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=1000000;i++)
        sum[i]=(!np[i])+sum[i-1];
    while(n--){
        scanf("%d%d",&l,&r);
        if(l<1||r>m)
            puts("Crossing the line");
        else
            printf("%d\n",sum[r]-sum[l-1]);
    }
    //system("pause");
    return 0;
}