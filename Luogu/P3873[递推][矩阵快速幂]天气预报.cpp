#include <cstdio>
#include <cstring>

const int N = 105, mod = 4147;
struct Matrix {
	int a[N][N];
	Matrix() {
		memset(a, 0, sizeof(a));
	}
};
int n, m, w[N];

Matrix multi(Matrix x, Matrix y) {
	Matrix r;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				r.a[i][j] += x.a[i][k] * y.a[k][j];
				r.a[i][j] %= mod;
			}
		}
	}
	return r;
}

Matrix ksm(Matrix x, int y) {
	Matrix res;
	for(int i = 1; i <= n; i++)
		res.a[i][i] = 1;
	while(y) {
		if(y & 1)
			res = multi(res, x);
		x = multi(x, x);
		y >>= 1;
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	Matrix ans;
	int p;
	for(int i = 1; i < n; i++)
		ans.a[i][i + 1] = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p);
		ans.a[i][1] = p;
	}
	ans = ksm(ans, m - n);
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum = (sum + ans.a[i][1] * w[i]) % mod;
	printf("%d\n", sum);
	return 0;
}