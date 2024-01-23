#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

const int MAXS = 110;

struct node {
    
    struct node *children[26];

    bool end;
};

struct node root;

void init(struct node *n) {
    n->end = false;

    for (int i = 0; i < 26; ++i) {
        n->children[i] = NULL;
    }
}

void add(char *s, int len) {
    struct node *cur = &root;
    for(int i = 0; i < len; ++i) {
        if(cur->children[s[i] - 'a'] == NULL) {
            cur->children[s[i] - 'a'] = (struct node *) malloc(sizeof(struct node));
            cur = cur->children[s[i] - 'a'];
            init(cur);
        } else {
            cur = cur->children[s[i] - 'a'];
        }
    }
    cur->end = true;
}


int main() {

    int t, ans;
    scanf("%d", &t);

    init(&root);

    while (t--) {
        char s[MAXS];
        scanf("%s", s);
        add(s, strlen(s));

        int slen = strlen(s);
        for(int i = 0; i < slen; ++i) {
            add(s+i, i+1);
            // add(s+slen-i-1, slen - i);
            printf("Added %s\n", s+i);
            // printf("Added %s\n", s+slen-i-1);
        }
        ans = 0;
        

    }
    

    return 0;
}