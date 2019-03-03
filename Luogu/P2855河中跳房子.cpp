#include <cstdio>
#include <algorithm>
using namespace std;
const int size = 50005;
int d[size], len, n, m;
/*
25 5 2
2
11
14
17
21
*/
inline bool check (int val)
{
	int p = 0, last = 0, maxn = n + 1;
	for (int i = 1; i <= maxn; i++)
	{
		if (d[i] - d[last] < val)
		{
			p++;
			if (p > m)
				return 0;
		}
		else
		    last = i;
	}
	return 1;
}
int main ()
{
	int result;
	scanf ("%d%d%d", &len, &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &d[i]);
	d[n + 1] = len;
    sort (d + 1, d + n + 1);
	int l = 0, r = len, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (check (mid))
		{
			result = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	printf ("%d\n", result);
	return 0;
}
