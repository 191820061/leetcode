#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};
Edge edge[100005];
int ways[400];
int n;
int m;
int ans;
int maxs;

void init() {
    for (int i = 1; i <= n; i++) {
        ways[i] = i;
    }
}

int find(int x) {
    if (ways[x] == x) {
        return x;
    }
    ways[x] = find(ways[x]);
    return ways[x];
}

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

void kruskal() {
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        if (find(edge[i].u) == find(edge[i].v)) {
            continue;
        }
        ans++;
        maxs = edge[i].w;
        ways[find(edge[i].u)]=edge[i].v;
        if (ans == n - 1) {
            break;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    init();
    kruskal();
    cout << ans << " " << maxs << endl;
}