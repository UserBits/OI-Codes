#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int len,last;
}p[100005];
int a[100005];
int main(){
	int n,ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	p[0].last=a[1];
	p[0].len=1;
	for(int i=2;i<=n;i++){
		bool flag=0;
		int minn=1<<30,id;
		for(int j=0;j<ans;j++){
			if(p[j].last+1==a[i]){
				flag=1;
				if(p[j].len<minn){
					minn=p[j].len;
					id=j;
				}
			}
		}
		if(!flag){
			p[ans].last=a[i];
			p[ans].len=1;
			ans++;
		}
		else{
			p[id].last++;
			p[id].len++;
		}
	}
	int maxn=1<<30;
	for(int i=0;i<ans;i++){
		maxn=min(maxn,p[i].len);
		//printf("%d %d\n",p[i].last,p[i].len);
    }
	printf("%d\n",maxn);
	return 0;
}

