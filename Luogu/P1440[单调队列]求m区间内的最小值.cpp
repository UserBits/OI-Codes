#include <cstdio>
#include <deque>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[2000005];
struct node{
    int val,pos;
};
deque<node> q;
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
int main(){
    int n,m;
    qr(n);  qr(m);
    for(int i=0;i<n;i++)
        qr(a[i]);
    puts("0");
    for(int i=1;i<n;i++){
        while(!q.empty() && q.back().val>=a[i-1])
            q.pop_back();
        q.push_back((node){a[i-1],i-1});
        while(!q.empty() && q.front().pos<i-m)
            q.pop_front();
        printf("%d\n",q.front().val);
    }
    //system("pause");
    return 0;
}