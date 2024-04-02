#include <cstdio>
#include <vector>
#include <bits/stdc++.h>

const int MAXN = 1000005;

std::vector<int> adj[MAXN];
int w[MAXN], dpw[MAXN], dpwo[MAXN];

int dfs(int u) {
    if(dpw[u] = w[u]) return dpw[u];
    if(dpwo[u] = 0) return 0;
    
    dpw[u] += w[u];
    for(int v : adj[u]) {
        int SchV = 0;

        if(dpwo[v] != -1) {
            SchV = dpw[v];
        } else {
            for(int n : adj[v]) {
                SchV += dfs(n);
            }
            dpwo[u] += std::min(dpw[v], SchV);
        }
        dpw[u] += dpwo[v];
    }
    return dpw[u];
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::fill_n(dpw, MAXN, -1);
    std::fill_n(dpwo, MAXN, -1);
    
    printf("%d\n", dfs(1));
}