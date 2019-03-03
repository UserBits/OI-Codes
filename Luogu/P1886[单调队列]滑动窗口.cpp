#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1000005;
struct node{
	int x,y;
}q[N];
int a[N],n,k;
inline void qr(int &s){
	s=0;
	int f=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-')
			f=-1;
	}
	for(;c>='0'&&c<='9';c=getchar())
		s=(s<<1)+(s<<3)+c-'0';
	s*=f;
}
void gmin(){
	int head=1,tail=0,i;
	for(i=1;i<k;i++){
		while(head<=tail && q[tail].x>=a[i])
			tail--;
		q[++tail].x=a[i];
		q[tail].y=i;
	}
	for(;i<=n;i++){
		while(head<=tail && q[tail].x>=a[i])
			tail--;
		q[++tail].x=a[i];
		q[tail].y=i;
		while(q[head].y<i-k+1)
			head++;
		printf("%d ",q[head].x);
	}
	puts("");
}
void gmax(){
	int head=1,tail=0,i;
	for(i=1;i<k;i++){
		while(head<=tail && q[tail].x<=a[i])
			tail--;
		q[++tail].x=a[i];
		q[tail].y=i;
	}
	for(;i<=n;i++){
		while(head<=tail && q[tail].x<=a[i])
			tail--;
		q[++tail].x=a[i];
		q[tail].y=i;
		while(q[head].y<i-k+1)
			head++;
		printf("%d ",q[head].x);
	}
	puts("");
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		qr(a[i]);
	gmin();
	gmax();	return 0;
}