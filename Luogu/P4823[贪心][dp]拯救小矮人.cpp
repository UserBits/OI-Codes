#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Save{
	int a,b;
}p[2005];

int n,h;
long long f[2005][2005],s[2005];
bool cmp(Save x,Save y){
	return x.a+x.b<y.a+y.b;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].a,&p[i].b);
	scanf("%d",&h);
	sort(p+1,p+1+n,cmp);
	for(int i=n;i>0;i--)
		s[i]=s[i+1]+p[i].a;
	for(int i=1;i<=n;i++){
		f[i][0]=f[i-1][0]+p[i].a;
		for(int j=1;j<=i;j++){
			f[i][j]=-1;
			if(f[i-1][j-1]>=0 && f[i-1][j-1]+s[i]+p[i].b>=h)
				f[i][j]=f[i-1][j-1];
			if(i>j && f[i-1][j]>=0)
				f[i][j]=max(f[i][j],f[i-1][j]+p[i].a);
		}
	}
	for(int i=n;i>=0;i--){
		if(f[n][i]>=0){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
