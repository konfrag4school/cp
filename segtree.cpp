#include <cstdio>
#include <memory>

const int MAXN = 1e5 + 5;
int a[MAXN], seg[4 * MAXN];
int n, q;

void build(int idx = 1, int start = 0, int end = n-1) {
    if(start == end) {
        seg[idx] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2*idx, start, mid);
    build(2*idx+1, mid+1, end);

    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

void Update(int pos, int val, int idx = 1, int start = 0, int end = n-1) {
    if(start == end) {
        seg[idx] += val;
        return;
    }

    int mid = (start + end) / 2;
    if(pos <= mid) {
        Update(pos, val, 2*idx, start, mid);
    } else {
        Update(pos, val, 2*idx+1, mid+1, end);
    }

    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

int Query(int from, int to, int idx = 1, int start = 0, int end = n - 1) {
    if(from == start && to == end) {
        return seg[idx];
    }

    int mid = (start + end) / 2;
    if(to <= mid) {
        return Query(from , to, 2*idx, start, mid);
    } else if(from > mid) {
        return Query(from, to, 2*idx+1, mid+1, end);
    } else {
        return Query(from, mid, 2*idx, start, mid) + Query(mid+1, to, 2*idx+1, mid+1, end);
    }

}

int main() {
    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    build();

    int op, a, b;
    while(q--) {
        scanf("%d %d %d", &op, &a, &b);
        if(op == 0) {
            Update(a, b);
        } else if(op == 1) {
            printf("%d\n", Query(a, b));
        } else {
            printf("Invalid operation\n");
        }
    }

}