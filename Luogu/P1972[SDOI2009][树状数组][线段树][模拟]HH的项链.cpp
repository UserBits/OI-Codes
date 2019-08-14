#include <cstdio>
#include <algorithm>
#include <cstdlib>

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

const int N=1000001;
struct Ques{
    int l,r,id;
    friend bool operator < (Ques p,Ques q){
        return p.r<q.r;
    }
}ques[N];
int tree[N],vis[N],ans[N],a[N];

#define lb(x) x&(-x)

inline void Update(int x,int y){
    while(x<N){
        tree[x]+=y;
        x+=lb(x);
    }
}

inline int Query(int x){
    int s=0;
    while(x){
        s+=tree[x];
        x-=lb(x);
    }
    return s;
}

int main(){
    int n,m;
    qr(n);
    for(int i=1;i<=n;i++)
        qr(a[i]);
    qr(m);
    for(int i=1;i<=m;i++){
        ques[i].id=i;
        qr(ques[i].l);
        qr(ques[i].r);
    }
    sort(ques+1,ques+1+m);
    ques[0].r=0;
    for(int i=1;i<=m;i++){
        for(int j=ques[i-1].r+1;j<=ques[i].r;j++){
            if(vis[a[j]])
                Update(vis[a[j]],-1);
            vis[a[j]]=j;
            Update(j,1);
        }
        ans[ques[i].id]=Query(ques[i].r)-Query(ques[i].l-1);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}  