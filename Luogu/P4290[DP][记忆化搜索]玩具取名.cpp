#include <cstdio>
#include <cstring>

using namespace std;

const int N = 201;
bool f[N][N][5], p[N][N][5];
char s[N];
int x[5];

namespace func{

    int letter_num(char c){
        switch(c){
            case 'W':   return 1;
            case 'I':   return 2;
            case 'N':   return 3;
            case 'G':   return 4;
        }
    }

    char num_letter(int x){
        switch(x){
            case 1:     return 'W';
            case 2:     return 'I';
            case 3:     return 'N';
            case 4:     return 'G';
        }
    }

    void pre(int cnt){
        char x[3];
        scanf("%s", x + 1);
        p[letter_num(x[1])][letter_num(x[2])][cnt] = 1;
    }

    void edit(int i, int j, int k){
        int x, y, res;
        for(x = 1; x <= 4; x++){
            for(y = 1; y <= 4; y++){
                for(res = 1; res <= 4; res++){
                    if(f[i][k][x] && f[k + 1][j][y] && p[x][y][res])
                        f[i][j][res] = 1;
                }
            }
        }
    }

}


void work(){
    for(int i = 1; i <= 4; i++)
        scanf("%d", &x[i]);
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= x[i]; j++)
            func :: pre(i);
    }
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for(int i = 1; i <= len; i++){
        int tp = func :: letter_num(s[i]);
        f[i][i][tp] = 1;
    }
    for(int l = 1; l <= len; l++){
        for(int i = 1; i <= len; i++){
            int j = i + l - 1;
            if(j > len)
                break;
            for(int k = i; k < j; k++)
                func :: edit(i, j, k);
        }
    }
    bool get_ans = 0;
    for(int i = 1; i <= 4; i++){
        if(f[1][len][i]){
            putchar(func :: num_letter(i));
            get_ans = 1;
        }
    }
    if(!get_ans)
        puts("The name is wrong!");
}

int main(){
    work();
    return 0;
}