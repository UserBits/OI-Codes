#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int N=200001;
typedef long long ll;
priority_queue<ll> q;
int a[N];
int main(){
    int n,k,t;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    getchar();
    ll ans=0; int last=0,ch;
    for(int i=1;i<=n;++i){
        ch=getchar()-'a';
        if(ch!=last){
            t=k;
            while(t>0 && !q.empty()){
                ans+=q.top(); q.pop(); t--;
            }
            while(!q.empty()) q.pop();
            last=ch;
        }
        q.push(a[i]);
    }
    t=k;
    while(t>0 && !q.empty()){
        ans+=q.top(); q.pop(); t--;
    }
    while(!q.empty()) q.pop();
    cout<<ans<<endl;
    return 0;
}