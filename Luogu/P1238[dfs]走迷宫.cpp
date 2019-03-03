#include <cstdio>
#include <cstdlib>
const int d[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int r[230][2],a[20][20],b[20][20],len,stx,sty,edx,edy,n,m;
bool flag=0;
void output(){
    flag=1;
    printf("(%d,%d)",r[1][0],r[1][1]);
    for(int i=2;i<=len;i++)
        printf("->(%d,%d)",r[i][0],r[i][1]);
    puts("");
}
void dfs(int x,int y){
    if(x==edx && y==edy){
        output();
        return;
    }
    int tx,ty;
    for(int i=0;i<4;i++){
        tx=x+d[i][0];
        ty=y+d[i][1];
        if(tx>0 && ty>0 && tx<=n && ty<=m && !b[tx][ty] && a[tx][ty]){
            b[tx][ty]=1;
            r[++len][0]=tx;
            r[len][1]=ty;
            dfs(tx,ty);
            b[tx][ty]=0;
            len--;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    }
    scanf("%d%d%d%d",&stx,&sty,&edx,&edy);
    b[stx][sty]=1;
    r[++len][0]=stx;
    r[len][1]=sty;
    dfs(stx,sty);
    if(!flag)
        puts("-1");
    return 0;
}