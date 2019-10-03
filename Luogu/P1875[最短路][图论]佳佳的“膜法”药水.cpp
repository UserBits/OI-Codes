#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1005;
int to[N][N], dis[N], sum[N];
bool vis[N];

int main() {
	int n, x, y, z;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &dis[i]);
		sum[i] = 1;
	}
	while(scanf("%d%d%d", &x, &y, &z) != EOF)
		to[x + 1][y + 1] = to[y + 1][x + 1] = z + 1;
	for(int i = 1; i < n; i++) {
		int mn = 1e9;
		for(int j = 1; j <= n; j++) {
			if(!vis[j] && dis[j] < mn) {
				x = j;
				mn = dis[j];
			}
		}
		vis[x] = 1;
		for(int j = 1; j <= n; j++) {
			if(vis[j] && to[x][j]) {
				if(dis[x] + dis[j] == dis[to[x][j]])
					sum[to[x][j]] += sum[x] * sum[j];
				if(dis[x] + dis[j] < dis[to[x][j]]) {
					dis[to[x][j]] = dis[x] + dis[j];
					sum[to[x][j]] = sum[x] * sum[j];
				}
			}
		}
	}
	printf("%d %d\n", dis[1], sum[1]);
	return 0;
}

