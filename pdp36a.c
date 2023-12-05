#include <cstdio>
#include <malloc.h>
#include <stack>

int main() {
    freopen("olivetrees.in", "r", stdin);
    freopen("olivetrees.out", "w", stdout);
    int n, m, top, ans = 0;
    scanf("%d %d", &n, &m);

    int *a = (int *) calloc(m+5, sizeof(int));

    a[0] = 0;
    a[m+1] = 0;
    for(int i = 1; i <= m; ++i) {
        scanf("%d", &a[i]);
        a[i] = n - a[i];
    }

    std::stack <int> s;
    s.push(0);
    for(int i = 1; i <= m+1; ++i) {
        if(a[s.top()] < a[i]) {
            s.push(i);
        } else {
            while(a[s.top()] > a[i]) {
                top = s.top();
                s.pop();
                ans = std::max(ans, (i-s.top()-1)*a[top]);
            }
            s.push(i);
        }
    }
    printf("%d\n", ans);

    return 0;
}