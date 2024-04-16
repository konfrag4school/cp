#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

const int MAXN = 6e4+5, MAXM = 2e5+5;

std::vector<std::pair<int, int>> adj[MAXN];
int dist[MAXN];

std::priority_queue<std::pair<int, int>> pq;

void dijkstra(int s) {
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(auto e : adj[u]) {
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        
        }
    }
}

void Xdijkstra(int s, int a) {
    dist[s] = 0;
    pq.push({0, s});

    bool visP = false;
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(auto e : adj[u]) {
            if(e.first == a) {
                continue;
            }
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        
        }
    }
}

int main() {
    freopen("supgame.in", "r", stdin);
    freopen("supgame.out", "w", stdout);
    int n, m, s, t, p, q;
    scanf("%d %d %d %d %d %d", &n, &m, &s, &t, &p, &q);

    for(int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
    }

    
    for(int i = 0; i <= MAXN; ++i) {
        dist[i] = 1e7;
    }
    Xdijkstra(s, q);
    int distP = dist[p];
    
    for(int i = 0; i <= MAXN; ++i) {
        dist[i] = 1e7;
    }
    dijkstra(p);
    int distPT = dist[t];

    
    for(int i = 0; i <= MAXN; ++i) {
        dist[i] = 1e7;
    }
    dijkstra(s);
    int distST = dist[t];

    if(distP + distPT > distST) {
        printf("%d\n", distST);
    } else {
        printf("%d\n", distP + distPT);
    }

    /*for(int i = 1; i <= n; ++i) {
        printf("%d ", dist[i]);
    }*/

    return 0;
}