// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[100005];
int main(){
	int n,q,x,y;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%d\n",upper_bound(a+1,a+1+n,y)-lower_bound(a+1,a+1+n,x));
	}
	return 0;
}
