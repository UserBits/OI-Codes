#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
const int N=100005,M=400005;
struct edge{
    int node,next,val;
}Edge[M];
bool Inq[N];
int Head[N],Dis[N],n,tot,st[70],ed[70];
void SPFA(int s){
    for(int i=1;i<=n;i++)
        Dis[i]=1e9;
    Dis[s]=0;
    queue<int> q;
    q.push(s);
    Inq[s]=1;
    int r;
    while(!q.empty()){
        r=q.front();
        q.pop();
        Inq[r]=0;
        for(int k=Head[r];k;k=Edge[k].next){
            if(Dis[r]+Edge[k].val<Dis[Edge[k].node]){
                Dis[Edge[k].node]=Dis[r]+Edge[k].val;
                if(!Inq[Edge[k].node]){
                    q.push(Edge[k].node);
                    Inq[Edge[k].node]=1;
                }
            }
        }
    }
}
char a[305][305];
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
inline void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].val=l;
    Head[x]=tot;
}
int main(){
    int ln,lm;
	cin>>ln>>lm;
	n=ln*lm;
    int s,t;
    for(int i=0;i<ln;i++){
        for(int j=0;j<lm;j++){
            cin>>a[i][j];
            if(a[i][j]=='@')
                s=i*lm+j+1;
            if(a[i][j]=='=')
                t=i*lm+j+1;
            if(a[i][j]>='A'&&a[i][j]<='Z'){
                if(!st[a[i][j]-'A'])
                    st[a[i][j]-'A']=i*lm+j+1;
                else
                    ed[a[i][j]-'A']=i*lm+j+1;
            }
        }
    }
    for(int i=0;i<ln;i++){
        for(int j=0;j<lm;j++){
            if(a[i][j]!='#'){
                int x,y;
                for(int k=0;k<4;k++){
                    x=i+d[k][0];
                    y=j+d[k][1];
                    if(x>=0 && y>=0 && x<ln && y<lm && a[x][y]!='#'){
						if(a[x][y]>='A'&&a[x][y]<='Z'&&st[a[x][y]-'A']&&ed[a[x][y]-'A']){
							int to=x*lm+y+1;
							if(to==st[a[x][y]-'A'])
								to=ed[a[x][y]-'A'];
							else
								to=st[a[x][y]-'A'];
							Add(i*lm+j+1,to,1);
						}
						else
							Add(i*lm+j+1,x*lm+y+1,1);
					}
                }
            }
        }
    }
    SPFA(s);
    printf("%d\n",Dis[t]);
    return 0;
}
