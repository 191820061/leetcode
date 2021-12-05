#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int S;
int P;
struct Point {
    double x;
    double y;
};
struct Edge {
    int u;
    int v;
    double w;
};
Edge edge[250005];
int net[505];
Point point[505];
int indexs;
double maxs;
int cnt;
int line;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

void init() {
    for (int i = 1; i <= P; i++) {
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
    line = S - 1;
    for (int i = 1; i < indexs; i++) {
        if (find(edge[i].u) == find(edge[i].v)) {
            continue;
        }
        maxs = edge[i].w;
        cnt++;
        net[find(edge[i].u)] = edge[i].v;
        if (cnt == P - 1 - line) {
            break;
        }
    }
}

int main() {
    cin >> S >> P;
    init();
    for (int i = 1; i <= P; i++) {
        cin >> point[i].x >> point[i].y;
    }
    indexs = 1;
    for (int i = 1; i < P; i++) {
        for (int j = i + 1; j <= P; j++) {
            edge[indexs].u = i;
            edge[indexs].v = j;
            edge[indexs].w = distance(point[i], point[j]);
            indexs++;
        }
    }
    kruskal();
    printf("%.2lf\n", maxs);
}