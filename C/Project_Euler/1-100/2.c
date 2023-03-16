#include <stdio.h>
#include <inttypes.h>

int64_t arr[1000000];

int64_t Ofeibonaqi(int64_t *arr, int64_t num) {
    int64_t ind, sum = 0;
    *(arr + 1) = 2;
    for (int i = 0; *(arr + i - 1) < num; i++) {
        if (i == 0) *arr = 1;
        if (i == 1) *(arr + i) = 2;
        *(arr + i) = *(arr + i - 1) + *(arr + i - 2); 
        ind = i;
    }
    for (int i = 0; i <= ind; i++) {
        if (*(arr + i) % 2 == 0) sum += *(arr + i);
    }
    return sum;
}

int main() {
    int64_t num;
    scanf("%ld", &num);
    printf("%ld\n", Ofeibonaqi(arr, num));
    return 0;
}