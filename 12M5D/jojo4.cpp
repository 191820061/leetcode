
#include <queue>
#include <iostream>

using namespace std;
#define Max 2147483647
struct Edge {
    int id;
    int to;
    int next;
    int w;
};

struct Node {
    int dis;
    int pos;
    int id;

    bool operator<(const Node &x) const {
        return x.dis < dis;
    }
};

int n;
int m;
int s;
int e;
int cnt;
int city_count[600];
int count_time[600];
int country[600];
int country_time[600];
int head[600];
int via[605];
Edge edge[300000];
int distances[605];
int begin_pos[600];
int sizes;

bool compare(Node &x, Node &y) {
    return y.dis < x.dis;
}

priority_queue<Node> q;

void init_head() {
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
}

void init_distance(int t) {
    for (int i = 1; i <= n; i++) {
        distances[i] = Max;
    }
    distances[s] = t;
}

void add_edge(int u, int v, int w, int id) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    edge[cnt].id = id;
    head[u] = cnt;
}


void dijkstra(int id) {
    q.push((Node) {0, s, id});
    while (!q.empty()) {
        Node cache = q.top();
        q.pop();
        if (via[cache.pos]) {
            continue;
        }
        via[cache.pos] = true;
        for (int i = head[cache.pos]; i != -1; i = edge[i].next) {
            int to = edge[i].to;
            int id = edge[i].id;
            int add_value = id == cache.id ? 0 : count_time[id];
            if (distances[to] > distances[cache.pos] + edge[i].w + add_value) {
                distances[to] = distances[cache.pos] + edge[i].w + add_value;
                if (!via[cache.pos]) {
                    q.push((Node) {distances[to], to, id});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> e;
    init_head();
    for (int i = 1; i <= m; i++) {
        cin >> city_count[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> count_time[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= city_count[i]; j++) {
            cin >> country[j];
            if (country[j] == s) {
                begin_pos[sizes++] = i;
            }
        }
        for (int j = 1; j <= city_count[i] - 1; j++) {
            cin >> country_time[j];
        }
        for (int j = 1; j <= city_count[i] - 1; j++) {
            add_edge(country[j], country[j + 1], country[j], i);
        }
    }
    int min = Max;
    for (int i = 0; i < sizes; i++) {
        init_distance(count_time[begin_pos[i]]);
        dijkstra(begin_pos[i]);
        if (distances[e] < min) {
            min = distances[e];
        }
    }
    cout << min << endl;
}