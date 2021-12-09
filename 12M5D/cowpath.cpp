#include <iostream>
#include <queue>

using namespace std;
#define Max 2147483647
int head[50005];
int cnt;
int n;
int m;
int b;
struct Edge {
    int to;
    int next;
    int w;
};

struct Node {
    long long dis;
    int pos;

    bool operator<(const Node &x) const {
        return x.dis < dis;
    }
};

Edge edge[200005];
long long distances[50005];
bool via[50005];
priority_queue<Node> q;
int order[50005][2];

void add_edge(int u, int v, int w) {
    cnt++;
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void init_head() {
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
}

void init_distance() {
    for (int i = 1; i <= n; i++) {
        distances[i] = Max;
    }
    distances[1] = 0;
}

void dijkstra() {
    q.push((Node) {0, 1});
    while (!q.empty()) {
        Node cache = q.top();
        q.pop();
        if (via[cache.pos]) {
            continue;
        }
        via[cache.pos] = true;
        for (int i = head[cache.pos]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if (distances[v] > distances[cache.pos] + edge[i].w) {
                distances[v] = distances[cache.pos] + edge[i].w;
            }
            if (!via[v]) {
                q.push((Node) {distances[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m >> b;
    init_head();
    init_distance();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dijkstra();
    for (int i = 1; i <= b; i++) {
        cin >> order[i][0] >> order[i][1];
    }
    for (int i = 1; i <= b; i++) {
        cout << distances[order[i][0]] + distances[order[i][1]] << endl;
    }
}