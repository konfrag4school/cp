#include <cstdio>
#include <vector>

const int MAXN = 100005;
const int MAXM = 100005;

std::vector<int> adj[MAXN];
int color[MAXN], lucky[MAXN];
bool vis[MAXN];

std::vector<int> lucky_numbers;

void dfs(int u) {
    vis[u] = true;
    lucky_numbers.push_back(u);
    if(color[u] == 1) {
        for(int v : lucky_numbers) {
            lucky[v] = 1;
        }
        lucky_numbers.clear();
        return;
    }
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    int a, b;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &color[i]);
    }

    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }

    for(int i = 0; i < n; ++i) {
        if(color[i] == 0) {
            for(int j = 0; j < n; ++j) {
                vis[j] = false;
            }
            lucky_numbers.clear();
            dfs(i);
        }
    }

    for(int i = 0; i < n; ++i) {
        printf("%d ", lucky[i]);
    }

}