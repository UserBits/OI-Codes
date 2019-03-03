#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char s[100005],a[105],b[105];
int main(){
    int len_s,len_a,len_b;
    scanf("%s%s%s",s,a,b);
    len_s=strlen(s);
    len_a=strlen(a);
    len_b=strlen(b);
    bool chk1=0,chk2=0;
    /* forward */
    int last=-1;
    for(int i=0;i<len_s;i++){
        bool get_ans=1;
        for(int j=0;j<len_a;j++){
            if(s[i+j]!=a[j]){
                get_ans=0;
                break;
            }
        }
        if(get_ans){
            last=i+len_a;
            break;
        }
    }
    if(last!=-1){
        for(int i=last;i<len_s;i++){
            bool get_ans=1;
            for(int j=0;j<len_b;j++){
                if(s[i+j]!=b[j]){
                    get_ans=0;
                    break;
                }
            }
            if(get_ans){
                chk1=1;
                break;
            }
        }
    }
    /* backward */
    last=-1;
    for(int i=len_s-1;i>=0;i--){
        bool get_ans=1;
        for(int j=0;j<len_a;j++){
            if(s[i-j]!=a[j]){
                get_ans=0;
                break;
            }
        }
        if(get_ans){
            last=i-len_a;
            break;
        }
    }
    if(last!=-1){
        for(int i=last;i>=0;i--){
            bool get_ans=1;
            for(int j=0;j<len_b;j++){
                if(s[i-j]!=b[j]){
                    get_ans=0;
                    break;
                }
            }
            if(get_ans){
                chk2=1;
                break;
            }
        }
    }
    if(chk1 && chk2)
        puts("both");
    else if(chk1)
        puts("forward");
    else if(chk2)
        puts("backward");
    else
        puts("fantasy");
    return 0;
}