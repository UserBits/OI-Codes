#include <cstdio>
#include <iostream>
using namespace std;
const int N=1005;
int n,m,f[N],target[N];
bool flag[N];
inline int Find(int x){
	if(x!=f[x])
		f[x]=Find(f[x]);
	return f[x];
}
inline void Union(int x,int y){
	register int p=Find(f[x]),q=Find(f[y]);
	f[p]=q;
}
int main(){
	int p,q;
	char c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>c>>p>>q;
		if(c=='F')
			Union(p,q);
		else{
			if(target[p]==0)
				target[p]=q;
			else
				Union(target[p],q);
			if(target[q]==0)
				target[q]=p;
			else
				Union(target[q],p);
		}
	}
	for(int i=1;i<=n;i++)
		flag[Find(i)]=1;
	p=0;
	for(int i=1;i<=n;i++){
		if(flag[i])
			p++;
	}
	printf("%d\n",p);
	return 0;
}
