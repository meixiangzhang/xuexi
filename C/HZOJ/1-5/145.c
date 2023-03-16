#include <stdio.h>
#include <string.h>

#define MAX_N 20

int main() {
    int N, length = 0, ind;
    char str[MAX_N][100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", &str[i] != EOF);
        if (strlen(str[i]) > length) ind = i;
    }
    printf("%s\n", str[ind]);
    return 0;
}