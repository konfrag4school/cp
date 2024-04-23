#include <stdio.h>
#include <stdbool.h>

const int MAXN = 1000005;

int main() {
    int n;
    scanf("%d", &n);
    char a[MAXN], b[MAXN];
    for(int i = 0; i < n; ++i) {
        scanf(" %c", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf(" %c", &b[i]);
    }


    // Debug
    for(int i = 0; i < n; ++i) {
        printf("%c ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < n; ++i) {
        printf("%c ", b[i]);
    }
}