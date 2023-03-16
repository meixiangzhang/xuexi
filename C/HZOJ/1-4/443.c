#include <stdio.h>

#define MAX_N 200

int main() {
    int L, M, arr[MAX_N + 5];
    scanf("%d%d", &L, &M);
    for (int i = 0; i < 2 * M; i += 2) {
        scanf("%d%d", arr + i, arr + i + 1);
    }
    
    return 0;
}