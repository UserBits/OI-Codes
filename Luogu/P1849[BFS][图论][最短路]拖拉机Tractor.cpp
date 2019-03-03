#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N=1005;
int mp[N][N],dis[N][N],n,stx,sty;
bool v[N][N];
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void bfs(){
	queue<pair<int, int> > Q;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			dis[i][j]=1e9;
	}
	dis[stx][sty]=0;
	v[stx][sty]=1;
	Q.push(make_pair(stx,sty));
	int x,y,p,q;
	while(!Q.empty()){
		x=Q.front().first; y=Q.front().second;
		Q.pop();
		v[x][y]=0;
		for(int i=0;i<4;i++){
			p=x+d[i][0]; q=y+d[i][1];
			if(p>=0 && q>=0 && p<N && q<N && dis[x][y]+mp[p][q]<dis[p][q]){
				dis[p][q]=dis[x][y]+mp[p][q];
				if(!v[p][q]){
					v[p][q]=1;
					Q.push(make_pair(p,q));
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&stx,&sty);
	int x,y;
	while(n--){
		scanf("%d%d",&x,&y);
		mp[x][y]=1;
	}
	bfs();
	printf("%d\n",dis[0][0]);
	return 0;
}
