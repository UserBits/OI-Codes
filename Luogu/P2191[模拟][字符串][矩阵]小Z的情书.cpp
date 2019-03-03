#include <cstdio>
int a[1005][1005],k[1005][1005];
int main(){
	int n;
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;){
			c=getchar();
			if(c=='O'||c=='#')
				k[i][j++]=c;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;){
			c=getchar();
			if(c>='A'&&c<='Z')
				a[i][j++]=c;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(k[i][j]=='O')
				putchar(a[i][j]);
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=n;i>0;i--){
			if(k[i][j]=='O')
				putchar(a[j][n-i+1]);
		}
	}
	for(int i=n;i>0;i--){
		for(int j=n;j>0;j--){
			if(k[i][j]=='O')
				putchar(a[n-i+1][n-j+1]);
		}
	}
	for(int j=n;j>0;j--){
		for(int i=1;i<=n;i++){
			if(k[i][j]=='O')
				putchar(a[n-j+1][i]);
		}
	}
	putchar('\n');
	return 0;
}
