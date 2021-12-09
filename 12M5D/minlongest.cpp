//
// Created by 13047 on 2021/12/8.
//

#ifndef INC_12M5D_PRIORITY_QUEUE_H
#define INC_12M5D_PRIORITY_QUEUE_H

#include <iostream>

#define DEFAULT_CPTY 30000

template<typename T>
class priority_list {
public:
    priority_list() : nofns(0), capacity(DEFAULT_CPTY), compare(&_compare) {
        pt = new T[capacity];
    }


    explicit priority_list(bool (*cmp)(T &, T &)) : nofns(0), capacity(DEFAULT_CPTY), compare(cmp) {
        pt = new T[capacity];
    }

    ~priority_list() {
        if (nullptr != pt) {
            delete[] pt;
            pt = nullptr;
        }
    }


    bool push(const T &t) {
        T *ptt = pt;
        pt[nofns++] = t;
        heap_up();
        return true;
    }

    bool pop() {
        if (nofns == 0)
            return false;
        if (nofns == 1) {
            nofns = 0;
            return true;
        }
        pt[0] = pt[nofns - 1];
        nofns--;
        heap_down();
        return true;
    }
    T top() {
        return pt[0];//返回队头元素
    }


    bool is_empty_pl() const {
        return 0 == nofns;
    }


private:

    void heap_up();

    void heap_down();

    void obj_cpy(T *dest, const T *sour, int n) {
        for (int i = 0; i < n; i++)
            dest[i] = sour[i];
    }

    bool static _compare(T &t1, T &t2) {
        return t1 < t2;
    }

private:
    T *pt;
    int nofns;
    int capacity;

    bool (*compare)(T &, T &);

};

template<typename T>
void priority_list<T>::heap_up() {
    T temp;
    int itr = nofns - 1;
    while (itr > 0) {
        if ((compare(pt[itr / 2], pt[itr]))) {
            temp = pt[itr];
            pt[itr] = pt[itr / 2];
            pt[itr / 2] = temp;
            itr = itr / 2;
            continue;
        }
        break;
    }
}

template<typename T>
void priority_list<T>::heap_down() {
    T temp;
    int pitr = 0, citr;
    while (pitr <= nofns / 2 - 1) {
        citr = pitr * 2 + 1;
        if (citr + 1 < nofns && compare(pt[citr], pt[citr + 1]))
            citr++;
        if ((compare(pt[pitr], pt[citr]))) {
            temp = pt[citr];
            pt[citr] = pt[pitr];
            pt[pitr] = temp;
            pitr = citr;
            continue;
        }
        break;
    }
}

#endif //INC_12M5D_PRIORITY_QUEUE_H

#include <iostream>

using namespace std;
#define Max 2147483647
int head[1005];
int cnt;
int n;
int m;
int s;
int e;
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

bool compare(Node &x, Node &y) {
    return y.dis < x.dis;
}

Edge edge[30000];
int distances[1005];
bool via[1005];
priority_list<Node> q(compare);

void add_edge(int u, int v, int w) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void init_head() {
    for (int i = 0; i <= n - 1; i++) {
        head[i] = -1;
    }
}

void init_distance() {
    for (int i = 0; i <= n - 1; i++) {
        distances[i] = Max;
    }
    distances[s] = 0;
}

void dijkstra() {
    q.push((Node) {0, s});
    while (!q.is_empty_pl()) {
        Node cache = q.top();
        q.pop();
        if (via[cache.pos]) {
            continue;
        }
        via[cache.pos] = true;
        for (int i = head[cache.pos]; i != -1; i = edge[i].next) {
            int to = edge[i].to;
            if (distances[to] > distances[cache.pos] + edge[i].w) {
                distances[to] = distances[cache.pos] + edge[i].w;
                if (!via[to]) {
                    q.push((Node) {distances[to], to});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> e;
    init_head();
    init_distance();
    for (int i = 1; i <= m; i++) {
        int country;
        cin >> country;
        int countrys[country + 1];
        int times[country + 1];
        for (int j = 1; j <= country; j++) {
            cin >> countrys[j];
        }
        for (int j = 1; j <= country - 1; j++) {
            cin >> times[j];
        }
        for (int j = 1; j <= country - 1; j++) {
            add_edge(countrys[j], countrys[j + 1], times[j]);
            add_edge(countrys[j + 1], countrys[j], times[j]);
        }
    }
    dijkstra();
    cout << distances[e] << endl;
}