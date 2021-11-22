#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n = 0;
    scanf("%d", &n);
    int result = -1;
    int a = 0;
    int b = 0;
    int x = 0;
    int y = 0;
    vector<vector<int>> cache;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &a, &b, &x, &y);
        cache.push_back(vector<int>{a, b, x, y});
    }
    scanf("%d %d", &x, &y);
    for (int i = cache.size() - 1; i >= 0; i--) {
        if (cache[i][0] <= x && cache[i][1] <= y && cache[i][0] + cache[i][2] >= x && cache[i][1] + cache[i][3] >= y) {
            result = i + 1;
            break;
        }
    }
    printf("%d\n",result);

}