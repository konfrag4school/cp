#include <cstdio>
#include <algorithm>

const int MAXN = 1e5+5;
const int LOG = 19;

int n, q;
int a[MAXN], sp[2*MAXN][LOG];

void build() {
    for(int i = 0; i < n; ++i) {
        sp[i][0] = a[i];
    }
   
    for(int k = 1; k < LOG; ++k) {
        for(int i = 0; i < n; ++i) {
            sp[i][k] = std::min(sp[i][k-1], sp[i+(1<<(k-1))][k-1]);
        }
    }
}

int rmq(int i, int j) {
    int k = 31-__builtin_clz(j-i+1);
    return std::min(sp[i][k], sp[j-(1<<(k))+1][k]);
}

int main() {
    scanf("%d ", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d ", &a[i]);
    }
   
    build();
   
    scanf("%d ", &q);
   
   // Debug
   printf("\n");
   
   for(int i = 0; i < n; ++i) {
        for(int k = 1; i+(1<<k)-1 < n; ++i) {
            printf("%d ", sp[i][k]);
        }
        printf("\n");
    }
   
   
    int i, j;
    while(q--) {
        scanf("%d %d ", &i, &j);
       
        printf("%d\n", rmq(i, j));
    }
};