#include <iostream>
#include <queue>

using namespace std;
#define Max 2147483647
struct Edge {
    int to;
    int next;
    int w;
};

struct Node {
    int dis;
    int pos;

    bool operator<(const Node &x) const {
        return x.dis < dis;
    }
};

int n;
int m;
int s;
int t;
int head[3000];
int distances[3000];
bool via[3000];
Edge edge[15000];
int cnt;
priority_queue<Node> q;

void init_head() {
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
}

void init_distance() {
    for (int i = 1; i <= n; i++) {
        distances[i] = Max;
    }
    distances[s] = 0;
}

void add_edge(int u, int v, int w) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void dijkstra() {
    q.push((Node) {0, s});
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
    cin >> n >> m >> s >> t;
    init_distance();
    init_head();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dijkstra();
    cout << distances[t] << endl;
}