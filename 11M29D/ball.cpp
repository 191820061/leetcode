#include <iostream>

using namespace std;

int n;
int m;
int meb[60][60];

int dfs(int x, int y) {
    if (x == 1 && y == 0) {
        return 1;
    } else if (y <= 0) {
        return 0;
    }
    if (meb[x][y] != -1) {
        return meb[x][y];
    }
    int right = x % n + 1;
    int left = x != 1 ? x - 1 : n;
    int right_result = 0;
    int left_result = 0;
    if (meb[right][y - 1] != -1) {
        right_result = meb[right][y - 1];
    } else {
        right_result = dfs(right, y - 1);
        meb[right][y - 1] = right_result;
    }
    if (meb[left][y - 1] != -1) {
        left_result = meb[left][y - 1];
    } else {
        left_result = dfs(left, y - 1);
        meb[left][y - 1] = left_result;
    }
    meb[x][y] = right_result + left_result;
    return left_result + right_result;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= 60; i++) {
        for (int j = 0; j <= 60; j++) {
            meb[i][j] = -1;
        }
    }
    dfs(1, m);
    cout << meb[1][m] << endl;
}