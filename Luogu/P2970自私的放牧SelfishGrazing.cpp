#include <cstdio>
#include <algorithm>
using namespace std;
int t[500005];
struct Cow{
	int s, e;
} cow[500005];
bool cmp (Cow x,Cow y){
	return x.e < y.e;
}
inline void qr (int &s){
	s = 0;
	char c = getchar ();
	for (; c < '0' || c > '9'; c = getchar ());
	for (; c >= '0' && c <= '9'; c = getchar())
		s = (s << 1) + (s << 3) + (c - '0');
}
int main (){
	int n, ans = 1, end;
	qr (n);
	for (int i = 0; i < n; i++)
		qr (cow[i].s), qr (cow[i].e);
	sort (cow,cow+n,cmp);
	end = cow[0].e;
	for (int i = 1; i < n; i++){
		if (cow[i].s >= end){
			ans++;
			end = cow[i].e;
		}
	}
	printf ("%d\n", ans);
	return 0;
}

