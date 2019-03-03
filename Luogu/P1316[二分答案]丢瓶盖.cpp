#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,a[100005];
inline bool check(int x){
	int cnt=1,last=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-last>=x){
			last=a[i];
			cnt++;
		}
	}
	return cnt>=m;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int l=0,r=2e9,mid,ans;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
