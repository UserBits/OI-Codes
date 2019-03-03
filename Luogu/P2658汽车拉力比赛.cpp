#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;
const int d[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int h[505][505],m,n,pi,pj,tx,ty;
bool f[505][505],t[505][505];
namespace my{
    #define EOL putchar('\n')
    #define SPACE putchar(32)
    const int INF=2147483647,INE=-2147483647;
    template<typename qRead>
        inline void qr(qRead &s){
            char c=getchar();
            s=0;
            int f=1;
            for(;c<'0'||c>'9';c=getchar()){
                if(c=='-')
                    f=-1;
            }
            for(;c>='0'&&c<='9';c=getchar())
                s=(s<<1)+(s<<3)+(c-'0');
            s*=f;
        }
    template<typename qWrite>
        inline void qw(qWrite s){
	        if(s<0){
		        s=-s;
		        putchar('-');
	        }
	        if(s>9)
		        qw(s/10);
	        putchar(s%10+'0');
        }
    template<typename MaxVal>
        inline MaxVal mx(MaxVal a,MaxVal b){
            return a>b?a:b;
        }
    template<typename MaxVal>
        inline MaxVal max3(MaxVal a,MaxVal b,MaxVal c){
            return mx(a,mx(b,c));
        }
    template<typename MinVal>
        inline MinVal mn(MinVal a,MinVal b){
            return a<b?a:b;
        }
    template<typename MinVal>
        inline MinVal min3(MinVal a,MinVal b,MinVal c){
            return mn(a,mn(b,c));
        }
}
struct node{
    int x,y;
};
inline bool check(int x){
    register int i,j;
    queue<node> q;
    memset(t,0,sizeof(t));
    t[pi][pj]=1;
    q.push((node){pi,pj});
    while(!q.empty()){
        node tmp=q.front();
        q.pop();
        for(i=0;i<4;++i){
            tx=tmp.x+d[i][0];
            ty=tmp.y+d[i][1];
            if(tx>0&&tx<=m&&ty>0&&ty<=n&&!t[tx][ty]
                &&abs(h[tx][ty]-h[tmp.x][tmp.y])<=x){
                t[tx][ty]=1;
                q.push((node){tx,ty});
            }
        }
    }
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            if(f[i][j]&&!t[i][j])
                return 0;
        }
    }
    return 1;
}
int main(){
    register int i,j,l=0,r=0,mid,ans;
    my::qr(m);
    my::qr(n);
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            my::qr(h[i][j]);
            r=my::mx(r,h[i][j]);
        }
    }
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j)
            my::qr(f[i][j]);  
    }
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            if(f[i][j]){
                pi=i;
                pj=j;
                break;
            }
        }
    }
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}