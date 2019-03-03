#pragma G++ optimize(O2)
#include <cstdio>
#include <algorithm>
#include <cstring>
const int M=100000,N=10000;
int n,m,s,t,head[N+5],cnt,d[N+5];
struct node{
	int from,to,next,val;
}edge[2*M+5];
inline void add(int x,int y,int z,int num){
	edge[num].from=x;
	edge[num].to=y;
	edge[num].val=z;
	edge[num].next=head[x];
	head[x]=num;
}
bool check(int depth){
	if(depth==t)
		return 1;
	for(int k=head[depth];k;k=edge[k].next){
		int tmp=edge[k].to;
		if(d[tmp]==0 && edge[k].val && tmp!=s){
			d[tmp]=k;
			if(check(tmp))
				return 1;
		}
	}
	return 0;
}
int main(){
	int ans=0,value,x,y,z;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	while(m--){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,++cnt);
		add(y,x,0,++cnt);
	}
	while(check(s)){
		value=2147483647;
		for(int i=d[t];i;i=d[edge[i].from])
			value=std::min(edge[i].val,value);
		ans+=value;
		for(int i=d[t];i;i=d[edge[i].from]){
			edge[i].val-=value;
			if(i&1)
				edge[i+1].val+=value;
			else
				edge[i-1].val+=value;
		}
		memset(d,0,sizeof(d));
	}
	printf("%d\n",ans);
	return 0;
}
