#include <cstdio>
#include <cmath>

int main(){
    double n, k;
    scanf("%lf%lf", &n, &k);
    double delta = 9 + 8 * n + 8 * k;
	double x = (sqrt(delta) - 3) / 2;
	double result = n - x;
    printf("%d\n", (int)result);
    return 0;
}
