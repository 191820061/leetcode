#include <iostream>
#include <algorithm>

using namespace std;
struct Point {
    int x;
    int y;
    int distance;
};
struct Edge {
    int u;
    int v;
    int w;
};

Edge edge[10005];
Point point[105];
int draw[105];
int ans;
int cnt;
int n;
int indexs;

int distance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

void init() {
    for (int i = 1; i <= n; i++) {
        draw[i] = i;
    }
}

int find(int x) {
    if (draw[x] == x) {
        return x;
    }
    draw[x] = find(draw[x]);
    return draw[x];
}

void kruskal() {
    sort(edge + 1, edge + indexs, cmp);
    for (int i = 1; i < indexs; i++) {
        if (find(edge[i].u) == find(edge[i].v)) {
            continue;
        }
        ans += edge[i].w;
        draw[find(edge[i].u)] = edge[i].v;
        cnt++;
        if (cnt == n - 1) {
            break;
        }
    }
}

int main() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> point[i].x >> point[i].y;
    }
    indexs = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edge[indexs].u = i;
            edge[indexs].v = j;
            edge[indexs].w = distance(point[i], point[j]);
            indexs++;
        }
    }
    kruskal();
    cout << ans << endl;
}