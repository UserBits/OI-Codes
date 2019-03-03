// luogu-judger-enable-o2
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
	double x,y;
}isd[1005];
struct data{
	double s,e;
}rad[1005];
bool cmp(data x,data y){
	return x.e<y.e;
}
bool p[1005];
int main(){
	int ans=0,n,i,j;
	double d,maxn=0,len;
	scanf("%d%lf",&n,&d);
	for(i=0;i<n;i++){
		scanf("%lf%lf",&isd[i].x,&isd[i].y);
		if(isd[i].y>maxn)
			maxn=isd[i].y;
	}
	if(maxn>d || d<0.0){
		printf("-1\n");
		return 0;
	}
	for(i=0;i<n;i++){
		len=sqrt(d*d-isd[i].y*isd[i].y);
		rad[i].s=isd[i].x-len;
		rad[i].e=isd[i].x+len;
	}
	sort(rad,rad+n,cmp);
	for(i=0;i<n;i++){
		if(!p[i]){
			p[i]=1;
			for(j=0;j<n;j++){
                if(!p[j] && rad[j].s<=rad[i].e)
                    p[j]=1;
            }
            ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

