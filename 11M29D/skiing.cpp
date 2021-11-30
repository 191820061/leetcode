#include <iostream>
#include <queue>

using namespace std;

int r;
int c;

int map[200][200];
int meb[200][200];

int max_num(int top, int under, int left, int right) {
    if (max(top, under) > max(left, right)) {
        return max(top, under);
    }
    return max(left, right);
}

int skiing(int x, int y) {
    if (x > r || y > c) {
        return 0;
    }
    if (meb[x][y] != 0) {
        return meb[x][y];
    }

    int top = 0;
    int under = 0;
    int left = 0;
    int right = 0;
    if (map[x][y] < map[x - 1][y]) {
        top = skiing(x - 1, y) + 1;
    }
    if (map[x][y] < map[x + 1][y]) {
        under = skiing(x + 1, y) + 1;
    }
    if (map[x][y] < map[x][y + 1]) {
        right = skiing(x, y + 1) + 1;
    }
    if (map[x][y] < map[x][y - 1]) {
        left = skiing(x, y - 1) + 1;
    }
    if (top == 0 && under == 0 && left == 0 && right == 0) {
        return 1;
    }
    int maxs = max_num(top, under, left, right);
    meb[x][y] = maxs;
    return maxs;
}

int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> map[i][j];
        }
    }
    int maxn = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            maxn = max(skiing(i, j), maxn);
        }
    }
    cout << maxn << endl;
}