#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
    int x,y,step,dir; // 坐标、步数
};
int src[55][55],best[55][55]; // 地图、最佳步数
const int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
vector<int> ans; // 存答案
int main(){
    int n,m,p;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&p);
            if(p) //方块图化为点阵图
                src[i][j]=src[i][j-1]=src[i-1][j]=src[i-1][j-1]=1;
            best[i][j]=1<<30;
        }
    }
    for(int i=1;i<=m;i++)
        src[n][i]=1;
    for(int i=1;i<=n;i++)
        src[i][m]=1; //周围一圈设为1
    int stx,sty,edx,edy,tx,ty;
    char stdir;
    node tmp;
    scanf("%d%d%d%d",&stx,&sty,&edx,&edy);
    cin>>stdir;
    if(stdir=='N')
        p=0;
    else if(stdir=='E')
        p=1;
    else if(stdir=='S')
        p=2;
    else if(stdir=='W')
        p=3; 
    queue<node> q;
    q.push((node){stx,sty,0,p});
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        if(tmp.x==edx && tmp.y==edy)
            ans.push_back(tmp.step);
        for(int i=0;i<4;i++){
            p=tmp.step+1;
            if(i!=tmp.dir){
                p++;
                if((i==0&&tmp.dir==2)||(i==1&&tmp.dir==3)||(i==2&&tmp.dir==0)||(i==3&&tmp.dir==1))
                    p++;//向后转
            }
            for(int j=1;j<=3;j++){
                tx=tmp.x+j*d[i][0];
                ty=tmp.y+j*d[i][1];
                if(tx>n || tx<1 || ty>m || ty<1 || src[tx][ty])
                    break;
                if(p<=best[tx][ty]){
                    q.push((node){tx,ty,p,i});
                    best[tx][ty]=p;
                }
            }
        }
    }
    int res=1<<30;
    p=ans.size();
    for(int i=0;i<p;i++)
        res=min(res,ans[i]);
    if(res==1<<30)  
        puts("-1");
    else    
        printf("%d\n",res);
    return 0;
}