#include <stdio.h>

const int MAXN = 1e6 + 5;

a[MAXN];

typedef struct node {
    node *children[2];
    int val;
} node;

node *root;

node* create() {
    node *n = (node *) malloc(sizeof(node));
    n->val = 0;

    n->children[0] = NULL;
    n->children[1] = NULL;
    return n;
}

void add(int *s) {
    node *cur = root;
    for(int i = 0; i < 32; ++i) {
        int idx = *s & (1 << i);
        if(cur->children[idx] == NULL) {
            cur->children[idx] = create();
        }
        cur->children[idx]->val = cur->val << 1 | idx;
        cur = cur->children[idx];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    a[0] = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a[i] ^= a[i - 1];
        add(a[i]);
    }

    return 0;
}