#include <stdio.h>
#include <malloc.h>

#define MAXN 1000
#define MOD 1000000007 // 1e9+7

int arr[MAXN];

int k, ans, cnt;

typedef struct node {
    struct node *children[10];
} node;

node *root;

node* create() {
    node *n = (node *) malloc(sizeof(node));

    for (int i = 0; i < 10; ++i) {
        n->children[i] = NULL;
    }
    return n;
}

void add_init(int s) {
    node *cur = root;
    for(int i = 0; i < k; ++i) {
        int dig = s%10;
        if(cur->children[dig] == NULL) {
            cur->children[dig] = create();
        }
        cur = cur->children[dig];
        s = s/10;
    }
}

void add(int s) {
    node *cur = root;
    for(int i = 0; i < k; ++i) {
        int dig = s%10;
        printf("dig: %d\n", dig);
        if(cur->children[dig] == NULL) {
            if(i == 0) {
                return;
            }
            ans = (ans + ((1<<i)-1)%MOD)%MOD;
            ++cnt;
            return;
        }
        cur = cur->children[dig];
        s = s/10;
    }
    ans += (1<<k)-1;
    ++cnt;
    return;
}

int main() {
    int n, q, y;

    scanf("%d %d %d", &k, &n, &q);

    for(int i = 0; i < n; ++i) {
        scanf("%d ", &arr[i]);
    }

    while(q--) {
        scanf("%d", &y);
        root = create();
        ans = 0;
        cnt = 0;
        add_init(y);
        for(int i = 0; i < n; ++i) {
            add(arr[i]);
        }
        printf("%d %d\n", cnt, ans);
    }

    return 0;
}