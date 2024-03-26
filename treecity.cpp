#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

const int MAXN = 1e6+5;

std::vector<std::pair<int, int>> adj[MAXN];
bool hasStudent[MAXN];
long long dist[MAXN];
int ans = 1e9+7;
int total = 0;

long long sum = 0;

/* O(n^2)
void dfs(int u, int e) {
    for(auto p : adj[u]) {
        if(p.first != e) {
            dfs(p.first, u);
            dist[p.first] = dist[u] + p.second;
            if(hasStudent[p.first]) {
                sum += dist[p.first];
            }
        }
    }
}
*/

int num[MAXN];

void dfs(int u, int e) {
    num[u] = hasStudent[u];

    for(auto p : adj[u]) {
        if(p.first == e) continue;
        dfs(p.first, u);
        num[u] += num[p.first];
    }
}

void dfs2(int u, int e, int cursum) {
    ans = std::min(ans, cursum);
    for(auto p : adj[u]) {
        dfs2(p.first, u, cursum + (2 * num[p.first] - total));
    }
}

int main() {
    /* O(n^2)
    dfs(1, -1);
    */

    /*
    1 -> 2
    ans = ans
            -(# students in subtree of 2) * dist(1, 2)
            +(# of the rest of the students in subtree of 1) * dist(1, 2)
        <=>
    ans = ans - ( (# students in subtree of 1) - (# students in subtree of 2) ) * dist(1, 2)

    let num[i] = (# students in subtree of i)

    Then,
    ans = ans
            - num[2] * dist(1, 2)
            +(num[1] - num[2]) * dist(1, 2)
        <=>
    ans = ans - (2 * num[2] - numb[1]) * dist(1, 2)
                \____________________/ 
                          \/
                          >0

    num[i] = (Σ num[j] + hasStudent[i])
            j ε child(i)

    if leaf:
        num[i] = hasStudent[i];

    */
   total = num[1];
   dfs(1, -1);

}