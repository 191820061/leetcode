#include <iostream>
#include <vector>

using namespace std;

int ways(int x, int y, vector<int> &end, vector<int> &horse) {
    if (x == end[0] && y == end[1]) {
        return 1;
    }
    if (x > end[0] || y > end[1]) {
        return 0;
    }
    if (x == horse[0] && y == horse[1]) {
        return 0;
    }
    if (x + 1 == horse[0] && y + 2 == horse[1]) {
        return 0;
    }
    if (x + 1 == horse[0] && y - 2 == horse[1]) {
        return 0;
    }
    if (x - 1 == horse[0] && y + 2 == horse[1]) {
        return 0;
    }
    if (x - 1 == horse[0] && y - 2 == horse[1]) {
        return 0;
    }
    if (x + 2 == horse[0] && y - 1 == horse[1]) {
        return 0;
    }
    if (x + 2 == horse[0] && y + 1 == horse[1]) {
        return 0;
    }
    if (x - 2 == horse[0] && y + 1 == horse[1]) {
        return 0;
    }
    if (x - 2 == horse[0] && y - 1 == horse[1]) {
        return 0;
    }
    return ways(x + 1, y, end, horse) + ways(x, y + 1, end, horse);
}

int main() {
    vector<int> end;
    vector<int> horse;
    int end_x = 0;
    int end_y = 0;
    int horse_x = 0;
    int horse_y = 0;
    cin >> end_x >> end_y >> horse_x >> horse_y;
    end.push_back(end_x);
    end.push_back(end_y);
    horse.push_back(horse_x);
    horse.push_back(horse_y);
    cout << ways(0, 0, end, horse) << endl;
}