#include <cstdio>
#include <cmath>

using namespace std;

#define lb(x) x&(-x)
typedef long long ll;
const int N = 100001;
ll a[N], tr[N];
int fa[N], n;

void sp(int& x, int& y) {
	x ^= y ^= x ^= y;
}

int get(int x) {
	if(x == fa[x])
		return x;
	return fa[x] = get(fa[x]);
}

void update(int x, ll y) {
	while(x <= n) {
		tr[x] += y;
		x += lb(x);
	}
}

ll query(int x) {
	ll ans = 0;
	while(x) {
		ans += tr[x];
		x -= lb(x);
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if(a[i] > 1)
			fa[i] = i;
		else
			fa[i] = i + 1;
		update(i, a[i]);
	}
	fa[n + 1] = n + 1;
	int dc, op, x, y;
	scanf("%d", &dc);
	while(dc--) {
		scanf("%d%d%d", &op, &x, &y);
		if(x > y)
			sp(x, y);
		if(op)
			printf("%lld\n", query(y) - query(x - 1));
		else {
			x = get(x);
			while(x <= y) {
				op = sqrt(a[x]);
				update(x, op - a[x]);
				a[x] = op;
				if(a[x] == 1)
					fa[x] = x + 1;
				x = get(x + 1);
			}
		}
	}
	return 0;
}
