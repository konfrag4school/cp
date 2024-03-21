#include <stdio.h>

int a[1000005], psa[1000005];
long long max = 0;

int main() {
    int n;
    // freopen("metoxes2.in", "r", stdin);
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    psa[n-1] = a[n-1];

    for(int i = n-2; i >= 0; --i) {
        psa[i] = psa[i+1] + a[i];
        if(psa[i] > max) {
            max = psa[i];
        }
    }

    // freopen("metoxes2.out", "w", stdout);
    printf("%lld\n", max);

}