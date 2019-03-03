#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;
const int d[5][2]={{1,0},{0,1},{-1,0},{0,-1},{0,0}};
bool v[305][305];
int t[305][305];
struct node{
    int x,y,p;
};
void bfs(){
    queue<node> q;
    v[0][0]=1;
    int tx,ty;
    node tmp;
    q.push((node){0,0,0});
    while(!q.empty()){
        tmp=q.front();
        if(t[tmp.x][tmp.y]==1<<30){
            printf("%d\n",tmp.p);
            return;
        }
        q.pop();
        for(int i=0;i<4;i++){
            tx=tmp.x+d[i][0];
            ty=tmp.y+d[i][1];
            if(tx>=0 && ty>=0 && tmp.p+1<t[tx][ty] && !v[tx][ty]){
                q.push((node){tx,ty,tmp.p+1});
                v[tx][ty]=1;
            }
        }
    }
    puts("-1");
}
int main(){
    for(int i=0;i<=305;i++){
        for(int j=0;j<=305;j++)
            t[i][j]=1<<30;
    }
    int n,x,y,tx,ty,m;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&x,&y,&m);
        for(int i=0;i<5;i++){
            tx=x+d[i][0];
            ty=y+d[i][1];
            if(tx>=0 && ty>=0)
                t[tx][ty]=min(t[tx][ty],m);
        }
    }
    if(t[0][0]==1<<30){
        puts("0");
        return 0;
    }
    bfs();
    //system("pause");
    return 0;
}