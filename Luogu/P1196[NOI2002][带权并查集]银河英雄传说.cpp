#include <iostream>
#include <cstdio>
#include <algorithm>
using std::cin;
using std::abs;
const int N=30005;
int father[N],front[N],number[N];
int find(int x){
	if(father[x]==x)
		return x;
	int tmp=father[x];
	father[x]=find(father[x]);
	front[x]+=front[tmp];
	number[x]=number[father[x]];
	return father[x];
}
int main(){
	int t,p,q;
	scanf("%d",&t);
	char c;
	for(int i=1;i<=30000;i++){
		father[i]=i;
		front[i]=0;
		number[i]=1;
	}
	while(t--){
		cin>>c;
		scanf("%d%d",&p,&q);
		int x=find(p),y=find(q);
		if(c=='M'){
			father[x]=y;
			front[x]+=number[y];
			number[x]+=number[y];
			number[y]=number[x];
		}
		if(c=='C'){
			if(x!=y)
				puts("-1");
			else
				printf("%d\n",abs(front[p]-front[q])-1);
		}
	}
	return 0;
}
