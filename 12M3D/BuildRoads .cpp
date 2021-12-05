#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int m;

struct Point {
    double X;
    double Y;
};

struct Edge {
    int u;
    int v;
    double w;
};
Edge edge[1000000];
Point point[1005];
int graph[1005];
int indexs;
int cnt;
double ans;

double distance(Point x, Point y) {
    return sqrt(pow((x.X - y.X), 2) + pow((x.Y - y.Y), 2));
}

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
    sort(edge+1, edge + indexs+1, cmp);
    for (int i = 1; i < indexs; i++) {
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
    for (int i = 1; i <= n; i++) {
        cin >> point[i].X >> point[i].Y;
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
    for (int i = 1; i <= m; i++) {
        cin >> edge[indexs].u >> edge[indexs].v;
        edge[indexs].w = 0;
        indexs++;
    }
    kruskal();
    printf("%.2lf\n",ans);
}