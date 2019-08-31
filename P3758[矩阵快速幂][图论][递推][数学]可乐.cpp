#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int mod = 2017;

int n;

struct matrix {
	int a[31][31];
	matrix() {
		memset(a, 0, sizeof(a));
	}
};

matrix multi(matrix x, matrix y) {
	matrix r;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k <= n; k++)
				r.a[i][j] += (x.a[i][k] * y.a[k][j] % mod) % mod;
		}
	}
	return r;
}

matrix ksm(matrix x, int y) {
	matrix r;
	for(int i = 0; i <= n; i++)
		r.a[i][i] = 1;
	while(y) {
		if(y & 1)
			r = multi(r, x);
		x = multi(x, x);
		y >>= 1;
	}
	return r;
}
int main() {
	int m, x, y, t;
	matrix p;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		p.a[x][y] = p.a[y][x] = 1;
	}
	for(int i = 0; i <= n; i++)
		p.a[i][i] = 1;
	for(int i = 1; i <= n; i++)
		p.a[i][0] = 1;
	scanf("%d", &t);
	matrix ans = ksm(p, t);
	int sum = 0;
	for(int i = 0; i <= n; i++)
		sum = (sum + ans.a[1][i]) % mod;
	printf("%d\n", sum);
	return 0;
}