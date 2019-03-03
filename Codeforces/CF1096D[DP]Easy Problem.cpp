#include <cstdio>
#include <algorithm>
using std::min;

int n,x;
char s[100005];
long long f[5];

int main(){
	scanf("%d",&n); scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(s[i]=='h')
			f[1]+=x;
		if(s[i]=='a')
			f[2]=min(f[1],f[2]+x);
		if(s[i]=='r')
			f[3]=min(f[2],f[3]+x);
		if(s[i]=='d')
			f[4]=min(f[3],f[4]+x);
	}
	printf("%lld\n",f[4]);
	return 0;
}
