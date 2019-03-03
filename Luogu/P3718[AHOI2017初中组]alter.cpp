#include <cstdio>
#include <algorithm>
using namespace std;
char s[100005];
int flag,len,low=2,high,n,k,a[100005];
bool check(int p){
	int tp=0;
	for(int i=1;i<=len;i++)
		tp+=(a[i]/(p+1));
	return tp<=k;
}
char change(char c){
	if(c=='F')
		return 'N';
	else
		return 'F';
}
int main(){
	scanf("%d%d",&n,&k);
	char c;
	for(int i=0;i<n;){
		c=getchar();
		if(c=='N'||c=='F'){
			s[i]=c;
			i++;
		}
	}
	flag=s[0];
	int tp=0,mid;
	for(int i=0;i<n;i++){
		if(s[i]!=flag)
			tp++;
		flag=change(flag);
	}
	if(tp<=k){
		printf("1\n");
		return 0;
	}
	len=1;
	a[1]=1;
	flag=s[0];
	for(int i=1;i<n;i++){
		if(s[i]==flag)
			a[len]++;
		else
		{
			len++;
			a[len]=1;
			flag=change(flag);
		}
	}
	for(int i=1;i<=len;i++)
		high=max(high,a[i]);
	while(low<=high){
		mid=(low+high)>>1;
		if(check(mid))
			high=mid-1;
		else
			low=mid+1;
	}
	printf("%d\n",low);
	return 0;
}

