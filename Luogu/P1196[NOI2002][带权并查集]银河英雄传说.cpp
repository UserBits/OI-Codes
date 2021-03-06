#include <cstdio>

char ss[1 << 17], *A = ss, *B = ss;
inline char gc(){
    return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? EOF : *A++;
}

template<typename qRead>
inline void readn(qRead &s){
    char c = gc();
    s = 0;
    for(; c < '0' || c > '9'; c = gc());
    for(; c >= '0' && c <= '9'; c = gc())
        s = (s << 1) + (s << 3) + (c - '0');
}

inline void readc(char &c){
	c = gc();
	while(c != 'M' && c != 'C')
		c = gc();
}

template<typename abt>
inline abt ab(abt x){
	return x > 0 ? x : -x;
}

const int N = 30001;
int f[N], dis[N], sum[N];

int getf(int x){
	if(x == f[x])
		return x;
	int k = f[x];
	f[x] = getf(f[x]);
	dis[x] += dis[k];
	sum[x] = sum[f[x]];
	return f[x];
}

void merge(int x, int y){
	x = getf(x);
	y = getf(y);
	if(x == y)
		return;
	f[x] = y;
	dis[x] = dis[y] + sum[y];
	sum[y] += sum[x];
	sum[x] = sum[y];
}

int query(int x, int y){
	int u = getf(x), v = getf(y);
	if(u != v)
		return -1;
	return ab(dis[x] - dis[y]) - 1;
}

int main(){
	int t;
	readn(t);
	for(int i = 1; i < 30001; i++){
		f[i] = i;
		sum[i] = 1;
	}
	int x, y;
	char c;
	while(t--){
		readc(c);
		readn(x), readn(y);
		if(c == 'M')
			merge(x, y);
		else
			printf("%d\n", query(x, y));
	}
	return 0;
}
