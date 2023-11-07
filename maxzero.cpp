#include <cstdio>
#include <malloc.h>
#include <unordered_map>

int main() {
    // freopen("maxzero.in", "r", stdin);
    // freopen("maxzero.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int *a = (int *)calloc(sizeof(int), n+5);

    a[0] = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
    }

    int ans = 0;
    std::unordered_map<int, int> m;
    m[0] = 0;
    for(int j = 1; j <= n+1; ++j) {
        if(m[a[j]] != 0) {
            ans = std::max(ans, j-m[a[j]]);
        }
        if(m[a[j]] == 0) {
            m[a[j]] = j;
        }
    }

    printf("%d\n", ans);
}