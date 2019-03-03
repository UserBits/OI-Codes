#include <cstdio>
#include <cstring>
using namespace std;
char ans[205],pre[205],mid[205];
void build(int n,char *pre,char *mid,char *ans)
{
	if(n<=0)
		return;
	int p=strchr(mid,pre[0])-mid;
	build(p,pre+1,mid,ans);
	build(n-p-1,pre+1+p,mid+p+1,ans+p);
	ans[n-1]=pre[0];
}
int main()
{
	scanf("%s\n%s",mid,pre);
	build(strlen(pre),pre,mid,ans);
	puts(ans);
	return 0;
}
