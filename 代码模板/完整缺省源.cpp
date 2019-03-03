#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define EOL putchar('\n')
#define SPACE putchar(32)
#define lowbit(x) (x&(-x))
const int INF=2147483647,INE=-2147483647;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename qRead>
inline void qr(qRead &s){
    char c=gc(); s=0;
    qRead f=1;
    for(;c<'0'||c>'9';c=gc()){
        if(c=='-')
            f=-1;
    }
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
    s*=f;
}
template<typename qWrite>
inline void qw(qWrite s){
	if(s<0){
		s=-s;
		putchar('-');
	}
	if(s>9)
		qw(s/10);
	putchar(s%10+'0');
}

int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    
    return 0;
}
