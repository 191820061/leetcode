#include <iostream>
#include <vector>

using namespace std;

int island(vector<vector<int>> &array) {
    int result = 0;
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array[0].size(); j++) {
            if (array[i][j] == 1) {
                if (j - 1 < 0) {
                    result++;
                } else if (array[i][j - 1] == 0) {
                    result++;
                }
                if (j + 1 == array[0].size()) {
                    result++;
                } else if (array[i][j + 1] == 0) {
                    result++;
                }
                if (i - 1 < 0) {
                    result++;
                } else if (array[i - 1][j] == 0) {
                    result++;
                }
                if (i + 1 == array.size()) {
                    result++;
                } else if (array[i + 1][j] == 0) {
                    result++;
                }
            }
        }
    }
    return result;
}

int main() {
    int x;
    int y;
    vector<vector<int>> array;
    cin >> x >> y;
    int ele;
    vector<int> cache;
    for (int i = 0; i < x; i++) {
        cache.clear();
        for (int j = 0; j < y; j++) {
            cin >> ele;
            cache.push_back(ele);
        }
        array.push_back(cache);
    }
    cout << island(array) << endl;
}