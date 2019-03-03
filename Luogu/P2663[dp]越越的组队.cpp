#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
bool p[105][10005];
int main(){
	int n,x,sum=0;
	scanf("%d",&n);
	p[0][0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		for(int j=i;j>=0;j--){
			for(int k=sum;k>=0;k--){
				if(p[j][k])
					p[j+1][k+x]=1;
			}
		}
		sum+=x;
	}
	int ans=sum;
	for(int i=sum;i>0;i--){
		if(p[n/2][i])
			ans=min(ans,abs(i*2-sum));
	}
	printf("%d\n",(sum-ans)/2);
	return 0;
}
