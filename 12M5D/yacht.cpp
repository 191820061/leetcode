#include <iostream>
#include <queue>

using namespace std;
#define MAX 2147483647

int head[205];
int distances[205];
int cnt;
int n;

struct Node {
    int dis;
    int pos;

    bool operator<(const Node &x) const {
        return x.dis < dis;
    }
};

struct Edge {
    int to;
    int next;
    int w;
};

Edge edge[40005];
priority_queue<Node> q;
bool via[205];

void add_edge(int u, int v, int w) {
    cnt++;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    head[u] = cnt;
}

void init_head() {
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
}

void init_distance() {
    for (int i = 1; i <= n; i++) {
        distances[i] = MAX;
    }
    distances[1] = 0;
}


void Dijkstra() {
    q.push((Node) {0, 1});
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
    cin >> n;
    init_head();
    init_distance();
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int w;
            cin >> w;
            add_edge(i, j, w);
        }
    }
    Dijkstra();
    cout << distances[n] << endl;
}