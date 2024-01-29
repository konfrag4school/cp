#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

const int MAXS = 110;

typedef struct node {
    struct node *children[26];
    bool end;
}node;

node *root;

node* create() {
    node *n = (node *) malloc(sizeof(node));
    n->end = false;

    for (int i = 0; i < 26; ++i) {
        n->children[i] = NULL;
    }
    return n;
}

int add(char *s, int len) {
    int isNewNode = 0;
    node *cur = root;
    for(int i = 0; i < len; ++i) {
        if(cur->children[s[i] - 'a'] == NULL) {
            cur->children[s[i] - 'a'] = create();
            isNewNode++;
        }
        cur = cur->children[s[i] - 'a'];
    }
    cur->end = true;
    return isNewNode;
}

/*
void removeTrie(char *s, int len) {
    node *cur = root;
    for(int i = 0; i < len; ++i) {
        if(cur->children[s[i] - 'a'] == NULL) {
            return;
        } else {
            cur = cur->children[s[i] - 'a'];
        }
    }
    cur->end = false;
}
*/

void freeTrie(node *n) {
    for(int i = 0; i < 26; ++i) {
        if(n->children[i]) {
            freeTrie(n->children[i]);
        }
    }
    free(n);
}

/*
bool check(char *s, int len) {
    struct node *cur = root;
    for(int i = 0; i < len; ++i) {
        if(cur->children[s[i] - 'a'] == NULL) {
            return false;
        } else {
            cur = cur->children[s[i] - 'a'];
        }
    }
    return cur->end;
}
*/

int countDistinctSubstrings(char *input) {
    node *root = create();
    int count = 1;
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        count += add(input + i, length - i);
    }

    freeTrie(root);
    return count;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        root = create();
        char s[MAXS];
        scanf("%s", s);
        printf("%d\n", countDistinctSubstrings(s));
    }
    
    return 0;
}