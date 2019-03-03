#include <cstdio>
#include <algorithm>
using std::sort;
struct node{
	int x,y,val;
}a[100005];
int a1[20005],b[20005];
bool cmp(node p,node q){
	return p.val>q.val;
}
inline int Find(int x){
	if(x!=a1[x])
		a1[x]=Find(a1[x]);
	return a1[x];
}
inline void Union(int x,int y){
	int p=Find(a1[x]),q=Find(a1[y]);
	a1[p]=q;
}
inline bool Check(int x,int y){
	int p=Find(a1[x]),q=Find(a1[y]);
	return p==q;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].val);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)
		a1[i]=i;
	for(int i=1;i<=m;i++){
		if(Check(a[i].x,a[i].y)){
			printf("%d\n",a[i].val);
			return 0;
		}
		else{
			if(!b[a[i].x])
				b[a[i].x]=a[i].y;
			else
				Union(b[a[i].x],a[i].y);
			if(!b[a[i].y])
				b[a[i].y]=a[i].x;
			else
				Union(b[a[i].y],a[i].x);
  		}
	}
	puts("0");
	return 0;
}
