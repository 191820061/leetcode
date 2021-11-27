#include <iostream>

using namespace std;

#include <iostream>
#include <deque>

using namespace std;

int n;
int m;
int maps[3000][3000];
int begin_x;
int begin_y;
int end_x;
int end_y;
int counts[3000][3000];
bool via[3000][3000];
int change_x[4] = {-1, 1, 0, 0};
int change_y[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string word;
        cin >> word;
        for (int j = 1; j <= m; j++) {
            if (word[j - 1] == '.') {
                maps[i][j] = 0;
            } else if (word[j - 1] == '#') {
                maps[i][j] = 1;
            } else if (word[j - 1] == 'm') {
                begin_x = i;
                begin_y = j;
                maps[i][j] = 0;
            } else if (word[j - 1] == 'd') {
                end_x = i;
                end_y = j;
                maps[i][j] = 0;
            }
        }
    }

    deque<pair<int, int>> deque;
    deque.push_front({begin_x, begin_y});
    counts[begin_x][begin_y] = 0;
    via[begin_x][begin_y] = true;
    while (!deque.empty()) {
        int xx = deque.back().first;
        int yy = deque.back().second;
        deque.pop_back();
        for (int i = 0; i < 4; i++) {
            int u = xx + change_x[i];
            int v = yy + change_y[i];
            if (u < 1 || u > n || v < 1 || v > m || via[u][v] || maps[u][v] == 1) {
                continue;
            }
            counts[u][v] = counts[xx][yy] + 1;
            deque.push_front({u, v});
            via[u][v] = true;
            if (u == end_x && v == end_y) {
                cout << counts[u][v] << endl;
                return 0;
            }
        }
    }
    cout << "No Way!" << endl;
}