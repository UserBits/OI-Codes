#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

const int N = 200;
int edge[N][N], deg[N];
stack<int> s;

void dfs(int u){
	for(int v = 'A'; v <= 'z'; v++){
		if(edge[u][v]){
			edge[u][v]--, edge[v][u]--;
			dfs(v);
		}
	}
	s.push(u);
}

void work(){
	int n, st = 0, mn = 1e9, cnt = 0;
	cin >> n;
	char x, y;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		edge[x][y]++, edge[y][x]++;
		deg[x]++, deg[y]++;
		if(x < mn)
			mn = x;
		if(y < mn)
			mn = y;
	}
	for(int i = 'A'; i <= 'z'; i++){
		if(deg[i] & 1){
			if(!st)
				st = i;
			cnt++;
			if(cnt > 2){
				puts("No Solution");
				return;
			}
		}
	}
	if(!st)
		st = mn;
	dfs(st);
	while(!s.empty()){
		putchar(s.top());
		s.pop();
	}
}

int main(){
	work();
	return 0;
}

