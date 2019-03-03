#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int a[1000005],b[1000005];
int main(){
    int lena=0,lenb=0; char c=getchar();
    bool flag=0;
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar()){
    	if(c!='0') flag=1;
    	if(flag || (c>'1'&&c<'9'))
			a[++lena]=c-'0';
	}
	flag=0;
	for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar()){
    	if(c!='0') flag=1;
    	if(flag || (c>'1'&&c<'9'))
			b[++lenb]=c-'0';
	}
    if(lena>lenb){
        puts(">"); return 0;
    }
    if(lena<lenb){
    	puts("<"); return 0;
	}
	for(int i=1;i<=lena;i++){
		if(a[i]<b[i]){
			puts("<"); return 0;
		}
		if(a[i]>b[i]){
			puts(">"); return 0;
		}
	}
	puts("=");
	return 0;
}
