#include <cstdio>
#include <queue>
using namespace std;
priority_queue<pair<int,int>, vector< pair<int,int> >, greater< pair<int, int> > > q;
const int N=100005;
int a[N],b[N],t[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[i]=1;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        q.push(make_pair(a[1]+b[i],i));
    }
    pair<int,int> d;
    while(n--){
        d=q.top();  q.pop();
        printf("%d ",d.first);
        q.push(make_pair(a[++t[d.second]]+b[d.second],d.second));
    }
    return 0;
}