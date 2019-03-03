#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int key,val;
	friend bool operator < (node x,node y){
		return x.val<y.val;
	}
}a[100005];
int main(){
	freopen("sorts.in","r",stdin);
	freopen("sorts.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		a[i].key=i;
		scanf("%d",&a[i].val);
	}
	stable_sort(a,a+n);
	int mx=0;
	for(int i=0;i<n;i++){
		if(a[i].key-i>mx)
			mx=a[i].key-i;
	}
	printf("%d\n",mx+1);
	return 0;
}
