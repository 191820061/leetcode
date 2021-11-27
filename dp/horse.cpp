#include <bits/stdc++.h>

using namespace std;
int black_x;
int black_y;
int white_x;
int white_y;
int change_x[12] = {2, 2, -2, -2, -1, -1, 1, 1, -2, -2, 2, 2};
int change_y[12] = {2, -2, 2, -2, -2, 2, -2, 2, 1, -1, 1, -1};
int counts[20][20];
bool via[20][20];

int bfs(int x, int y) {

    deque<pair<int, int>> deque;
    deque.push_front({x, y});
    counts[x][y] = 0;
    via[x][y] = true;
    while (!deque.empty()) {
        int xx = deque.back().first;
        int yy = deque.back().second;
        deque.pop_back();
        for (int i = 0; i < 12; i++) {
            int u = xx + change_x[i];
            int v = yy + change_y[i];
            if (u < 1 || u > 20 || v < 1 || v > 20 || via[u][v]) {
                continue;
            }
            via[u][v] = true;
            deque.push_front({u, v});
            counts[u][v] = counts[xx][yy] + 1;
            if (u == 1 && v == 1) {
                return counts[1][1];
            }
        }
    }
    return counts[1][1];
}

void init() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            counts[i][j] = 0;
            via[i][j] = false;
        }
    }
}

int main() {
    cin >> black_x >> black_y >> white_x >> white_y;
    cout << bfs(black_x, black_y) << endl;
    init();
    cout << bfs(white_x, white_y) << endl;
}