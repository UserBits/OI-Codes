#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;
int a[35][35],n;
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node{
    int x,y;
};
void bfs(int stx,int sty){
    a[stx][sty]=3;
    queue<node> q;
    q.push((node){stx,sty});
    node tmp;
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            stx=tmp.x+d[i][0];
            sty=tmp.y+d[i][1];
            if(stx>=1&&stx<=n&&sty>=1&&sty<=n&&a[stx][sty]==0){
                a[stx][sty]=3;
                q.push((node){stx,sty});
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=n;i++){
        if(a[1][i]==0)
            bfs(1,i);
        if(a[i][1]==0)
            bfs(i,1);
        if(a[n][i]==0)
            bfs(n,i);
        if(a[i][n]==0)
            bfs(i,n);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==3)
                printf("0 ");
            if(a[i][j]==0)
                printf("2 ");
            if(a[i][j]==1)
                printf("1 ");
        }
        puts("");
    }
    //system("pause");
    return 0;
}