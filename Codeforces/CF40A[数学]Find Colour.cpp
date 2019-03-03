#include <cstdio>
#include <cmath>
int main(){
	int x,y;
	double n;
	scanf("%d%d",&x,&y);
	n=sqrt(x*x+y*y);
	if(ceil(n)>n){
		if(x*y>0 == (( (int)(ceil(n)) )&1))
			puts("black");
		else
			puts("white");
	}
	else
		puts("black");
	return 0;
}
