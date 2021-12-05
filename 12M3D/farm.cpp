#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

int cnt;
int maxs;
int n;
int m;
int farm[2005];
Edge edge[10005];

void init() {
    for (int i = 1; i <= n; i++) {
        farm[i] = i;
    }
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x) {
    if (farm[x] == x) {
        return x;
    }
    farm[x] = find(farm[x]);
    return farm[x];
}

void kruskal() {
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        if (find(edge[i].u) == find(edge[i].v)) {
            continue;
        }
        maxs = edge[i].w;
        farm[find(edge[i].u)] = edge[i].v;
        cnt++;
        if (cnt == n - 1) {
            break;
        }
    }
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    kruskal();
    cout << maxs << endl;

}