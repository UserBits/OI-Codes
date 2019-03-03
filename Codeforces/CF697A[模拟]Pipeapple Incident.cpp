#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    int t,s,x;
    scanf("%d%d%d",&t,&s,&x);
    if(x==t){
        puts("YES");
        return 0;
    }
    if((x-t)<s){
        puts("NO");
        return 0;
    }
    int p=(x-t)/s,r=(x-t)%s;
    if(r==0 || r==1)
        puts("YES");
    else
        puts("NO");
    return 0;
}
