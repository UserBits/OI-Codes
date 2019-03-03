#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
using namespace std;
struct node{
    int height,cnt;
};
stack<node> s;
int main(){
    int n; long long ans=0;
    scanf("%d",&n);
    node x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x.height);
        x.cnt=1;
        while(!s.empty() && s.top().height<=x.height){
            ans+=s.top().cnt;
            if(s.top().height==x.height)
                x.cnt+=s.top().cnt;
            s.pop();
        }
        if(!s.empty())
            ans++;
        s.push(x);
    }
    printf("%lld\n",ans);
    return 0;
}