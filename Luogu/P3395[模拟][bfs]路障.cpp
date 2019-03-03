#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int p[1005][1005],n;
bool v[1005][1005];
const int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}
struct node{
    int x,y,t;
};
void bfs(){
    v[1][1]=1;
    queue<node> q;
    int tx,ty;
    node tmp;
    q.push((node){1,1,0});
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        if(tmp.x==n&&tmp.y==n){
            puts("Yes");
            return;
        }
        for(int i=0;i<4;i++){
            tx=tmp.x+d[i][0];
            ty=tmp.y+d[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&!v[tx][ty]&&tmp.t+1<=p[tx][ty]){
                v[tx][ty]=1;
                q.push((node){tx,ty,tmp.t+1});
            }
        }
    }
    puts("No");
}
int main(){
    int t,m,x,y;
    qr(t);
    while(t--){
        qr(n);
        //printf("%d\n",n);
        m=n*2-2;
        memset(p,127,sizeof(p));
        memset(v,0,sizeof(v));
        for(int i=1;i<=m;i++){
            qr(x);
            qr(y);
            p[x][y]=i;
        }
        bfs();
    }
    //system("pause");
    return 0;
}