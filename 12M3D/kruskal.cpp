#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

Edge edge[300000];
int n;
int m;
int graph[5005];
int ans;
int cnt;

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

int find(int x) {
    if (graph[x] == x) {
        return x;
    }
    graph[x] = find(graph[x]);
    return graph[x];
}

void kruskal() {
    sort(edge, edge + m, cmp);
    for (int i = 1; i <= m; i++) {
        if (find(edge[i].u) == find(edge[i].v)) {
            continue;
        }
        ans += edge[i].w;
        graph[find(edge[i].u)] = find(edge[i].v);
        cnt++;
        if (cnt == n - 1) {
            break;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        graph[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    kruskal();
    if (cnt == n - 1) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
}