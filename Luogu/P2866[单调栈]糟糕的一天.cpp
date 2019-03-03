#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
stack<int> s;
int main(){
    int n,x;
    scanf("%d",&n);
    long long ans=0;
    while(n--){
        scanf("%d",&x);
        while(!s.empty() && s.top()<=x)
            s.pop();
        ans+=s.size();
        s.push(x);
    }
    printf("%lld\n",ans);
    return 0;
}