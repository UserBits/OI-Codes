#include <cstdio>
#include <cstdlib>
using namespace std;
const long long mod=12345678910;
int a[100005],n;
long long dfs(int &x){
    long long sum=0;
    while(a[x]==0){
        if(a[x+1]){ //相邻的左右括号，可以直接匹配
            sum++;
            x++;  //将右括号跳过
        }
        else{
            x++;
            sum=(sum+2*dfs(x))%mod;  //嵌套关系
        }
        x++;
    }
    return sum;
}
int main(){
    scanf("%d",&n);
    a[n+1]=1;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int tmp=1;
    printf("%lld\n",dfs(tmp));
    //system("pause");
    return 0;
}