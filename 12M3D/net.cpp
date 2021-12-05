#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

int n;
Edge edge[10000];
int net[105];
int ans;
int cnt = 0;
int indexs;
int distances[105][105];

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

void init() {
    for (int i = 1; i <= n; i++) {
        net[i] = i;
    }
}

int find(int x) {
    if (net[x] == x) {
        return x;
    }
    net[x] = find(net[x]);
    return net[x];
}

void kruskal() {
    sort(edge + 1, edge + indexs, cmp);
    for (int i = 1; i <= indexs - 1; i++) {
        if (find(edge[i].u) == find(edge[i].v)) {
            continue;
        }
        ans += edge[i].w;
        net[find(edge[i].u)] = edge[i].v;
        cnt++;
        if (cnt == n - 1) {
            break;
        }
    }
}

int main() {
    cin >> n;
    indexs = 1;
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> distances[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edge[indexs].u = i;
            edge[indexs].v = j;
            edge[indexs].w = distances[i][j];
            indexs++;
        }
    }
    kruskal();
    cout<<ans<<endl;

}