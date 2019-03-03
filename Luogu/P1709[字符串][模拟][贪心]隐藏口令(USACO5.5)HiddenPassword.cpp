#include <cstdio>
#include <cstring>
using namespace std;
const int size=10000005;
char s[size],t[size],c;
int len,ans,i,j;
int main(){
	scanf("%d",&len);
	for(i=0;i<len;){
		c=getchar();
		if(c>='a'&&c<='z'){
			s[i]=c;
			t[i]='z';
			i++;
		}
	}
	s[len]='z';
	for(i=0;i<len;i++){
		if(s[i]>s[i+1])
			break;
	}
	if(i==len)
	{
		printf("0\n");
		return 0;
	}
	s[len]='\0';
	//puts(s);
	//puts(t);
	for(i=0;i<len;i++){
		//printf("--- ID: %d ---\n",i);
		//printf("Compare Result: %d\n",strcmp(s+i,t));
		//printf("The two strings: %s --  %s\n",s+i,t);
		if(strcmp(s+i,t)<0){
			strcpy(t,s+i);
			ans=i;
		}
		s[i+len]=s[i];
	}
	printf("%d\n",ans);
}
