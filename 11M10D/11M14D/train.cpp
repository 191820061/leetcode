#include <iostream>
#include <unordered_map>

using namespace std;

void solve(unordered_map<int, int> &map) {

}

int main() {
    int n;
    int a;
    int b;
    cin >> n >> a >> b;
    unordered_map<int, int> map;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        map.emplace(array[i], -1);
    }
    for (int i = 0; i < n; i++) {

    }
    for (int i = 0; i < n; i++) {
        if (map[array[i]] == -1) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << map[array[i]] << " ";
    }
}