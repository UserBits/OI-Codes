#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int n,t,DC,p,q;
bool mp[5][105],v[5][105],get_ans;
void dfs(int x,int y){
	if(y>n){
		get_ans=1; return;
	}
	if(v[x][y] || get_ans)
		return;
	v[x][y]=1;
		for(int i=-1;i<=1;i++){
			if(x+i>=1 && x+i<=3 && !mp[x][y+1] && !mp[x+i][y+1] && !mp[x+i][y+2] && !mp[x+i][y+3])
				dfs(x+i,y+3);
		}
}
int main(){
	scanf("%d",&DC);
	while(DC--){
		cin>>n>>t;
		memset(mp,0,sizeof(mp));
		register char c;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				cin>>c;
				if(c=='s')
					p=i,q=j;
				if(c>='A' && c<='Z')
					mp[i][j]=1;
			}
		}
		memset(v,0,sizeof(v));
		get_ans=0;
		dfs(p,q);
		if(get_ans)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
