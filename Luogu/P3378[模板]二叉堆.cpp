#include <cstdio>
#include <algorithm>
using std::swap;
int a[1000005],hsize;
#define qr(a) scanf("%d",&a)
void hin(int d)
{
	a[++hsize]=d;
	int now=hsize,tmp;
	while(now>1)
	{
		tmp=now>>1;
		if(a[now]>=a[tmp])
			return;
		swap(a[tmp],a[now]);
		now=tmp;
	}
}
int hout()
{
	int ans=a[1],now=1,tmp;
	a[1]=a[hsize--];
	while((now<<1)<=hsize)
	{
		tmp=now<<1;
		if(tmp<hsize && a[tmp+1]<a[tmp])
			tmp++;
		if(a[now]<=a[tmp])
			break;
		swap(a[now],a[tmp]);
		now=tmp;
	}
	return ans;
}
int main(){
	//freopen("test.out","w",stdout);
	int n,s,x;
	qr(n);
	while(n--){
		qr(s);
		if(s==1){
			qr(x);
			hin(x);
		}
		if(s==2)
			printf("%d\n",a[1]);
		if(s==3)
			hout();
	}
	return 0;
}
