#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000005;
typedef long long ll;
bool np[N];
int p[N >> 1], s;
void pre() {
	np[0] = np[1] = 1;
	for(int i = 2; i < N; i++) {
		if(!np[i])
			p[++s] = i;
		for(int j = 1; j <= s && i * p[j] < N; j++) {
			np[i * p[j]] = 1;
			if(i % p[j] == 0)
				break;
		}
	}
}

int main() {
	pre();
	int n;
	ll x, r;
	scanf("%d", &n);
	while(n--) {
		cin >> x;
		r = sqrt(x);
		if(r * r == x && !np[r])
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
