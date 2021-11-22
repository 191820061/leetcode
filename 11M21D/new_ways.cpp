#include <iostream>
#include <vector>

using namespace std;

long long ways(int end_x, int end_y, int horse_x, int horse_y) {
    vector<vector<long long>> status(end_x + 1, vector<long long>(end_y + 1, 1));
    for (int i = end_x; i >= 0; i--) {
        for (int j = end_y; j >= 0; j--) {
            if (i == horse_x && j == horse_y) {
                status[i][j] = 0;
            } else if (i + 1 == horse_x && j + 2 == horse_y) {
                status[i][j] = 0;
            } else if (i + 1 == horse_x && j - 2 == horse_y) {
                status[i][j] = 0;
            } else if (i - 1 == horse_x && j + 2 == horse_y) {
                status[i][j] = 0;
            } else if (i - 1 == horse_x && j - 2 == horse_y) {
                status[i][j] = 0;
            } else if (i + 2 == horse_x && j + 1 == horse_y) {
                status[i][j] = 0;
            } else if (i + 2 == horse_x && j - 1 == horse_y) {
                status[i][j] = 0;
            } else if (i - 2 == horse_x && j + 1 == horse_y) {
                status[i][j] = 0;
            } else if (i - 2 == horse_x && j - 1 == horse_y) {
                status[i][j] = 0;
            } else if (i == end_x && j == end_y) {
                status[i][j] = 1;
            } else if (i == end_x) {
                status[i][j] = status[i][j + 1];
            } else if (j == end_y) {
                status[i][j] = status[i + 1][j];
            } else {
                status[i][j] = status[i + 1][j] + status[i][j + 1];
            }
        }
    }
    return status[0][0];
}

int main() {
    vector<int> end;
    vector<int> horse;
    int end_x = 0;
    int end_y = 0;
    int horse_x = 0;
    int horse_y = 0;
    cin >> end_x >> end_y >> horse_x >> horse_y;
    cout << ways(end_x, end_y, horse_x, horse_y) << endl;
}