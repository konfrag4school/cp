#include <stdio.h>

const int MAXN = 1000005;
int a[MAXN];
int b[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int cnt = 0;
        for (int k = 0; k < 31-__builtin_clz(a[i]); ++k) {
            if (a[i] & (1 << k)) {
                cnt++;
            }
        }
        b[cnt]++;
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(b[i] > ans) {
            ans = b[i];
        }
    }
    printf("%d\n", ans);

    return 0;
}