#include <iostream>
#include <queue>

using namespace std;
#define MAX 2147483647
struct Edge {
    int next;
    int to;
    int w;
};

struct Node {
    int dis;
    int pos;

    bool operator<(const Node &x) const {
        return x.dis < dis;
    }
};

int head[100005];
Edge edge[500005];
int distances[100005];
bool via[100005];
int n;
int m;
int cnt;
int s;
priority_queue<Node> q;


void init_head() {
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
}

void init_distance() {
    for (int i = 1; i <= n; i++) {
        distances[i] = MAX;
    }
    distances[s] = 0;
}

void add_edge(int u, int v, int w) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
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
            int y = edge[i].to;
            if (distances[y] > distances[cache.pos] + edge[i].w) {
                distances[y] = distances[cache.pos] + edge[i].w;
                if (!via[y]) {
                    q.push((Node) {distances[y], y});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    init_head();
    init_distance();
    int u;
    int v;
    int w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << distances[i] << " ";
    }
    printf("\n");
}