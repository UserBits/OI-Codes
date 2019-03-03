#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int x[10005],y[10005];
int main(){
	double ans=0.0,pos=0.0;
	int sum=1,n,lx=0,ly=0;
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='T'){
			lx++;
			cin>>x[lx];
		}
		else{
			ly++;
			cin>>y[ly];
		}
	}
	sort(x+1,x+1+lx);
	sort(y+1,y+1+ly);
	x[lx+1]=1<<30;
	y[ly+1]=1<<30;
	int i=1,j=1;
	while(i<=lx || j<=ly){
		double tmp=1.0/sum;
		double s1=pos+(x[i]*1.0-ans)*tmp,s2=y[j];
		if(s1<s2){
			pos=s1;
			ans=x[i];
			i++;
		}
		else{
			ans+=(s2-pos)/tmp;
			pos=s2;
			j++;
		}
		sum++;
	}
	ans+=(1000-pos)/(1.0/sum);
	printf("%d\n",(int)(ans+0.5));
	return 0;
}