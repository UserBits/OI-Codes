#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[105],f[25005];
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		f[0]=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans=0;
		sort(a+1,a+1+n);
		n=unique(a+1,a+1+n)-a-1;
		for(int i=1;i<=n;i++){
			if(!f[a[i]]){
				ans++;
				f[a[i]]=1;
			}
			for(int j=a[i]+1;j<=a[n];j++){
				if(f[j-a[i]])
					f[j]=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
