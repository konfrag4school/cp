#include <stdio.h>
#include <malloc.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *a = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
        a[i] = n - a[i];
    }

    for(int i = 0; i < m; ++i) {
        printf("%d", a[i]);
    }

    return 0;
}