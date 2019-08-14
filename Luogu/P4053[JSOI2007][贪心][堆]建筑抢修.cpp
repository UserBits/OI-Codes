#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
inline void qr(int &s){
	s=0;
	char c=gc();
	for(;c<'0'||c>'9';c=gc());
	for(;c>='0'&&c<='9';c=gc())
		s=(s<<1)+(s<<3)+c-'0';
}

const int N=150005;
struct building{
    int t,v;
    friend bool operator < (building x,building y){
        return x.t<y.t;
    }
}a[N];

priority_queue<int> q;

int main(){
    int n;
    qr(n);
    for(int i=1;i<=n;i++)
        qr(a[i].v),qr(a[i].t);
    sort(a+1,a+1+n);
    int now=0,ans=0;
    for(int i=1;i<=n;i++){
        if(now+a[i].v>a[i].t){
            if(a[i].v<q.top()){
                now-=q.top();
                q.pop();
                now+=a[i].v;
                q.push(a[i].v);
            }
        }
        else{
            q.push(a[i].v);
            now+=a[i].v;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}