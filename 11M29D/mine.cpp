#include <iostream>
#include <deque>

using namespace std;

int n;
int mine_count[50];
int mines[50][50];
int meb[50];
int nexts[30];

int dfs(int x) {
    if (meb[x] != 0) {
        return meb[x];
    }
    int result = mine_count[x];
    int pos = -1;
    for (int i = 1; i <= n - x; i++) {
        if (mines[x][i] == 1) {
            int count = mine_count[x] + dfs(x + i);
            if (count > result) {
                pos = x + i;
                result = count;
            }
        }
    }
    nexts[x] = pos;
    meb[x] = result;
    return result;
}

void init() {
    for (int i = 1; i <= 50; i++) {
        meb[i] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> mine_count[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            cin >> mines[i][j];
        }
    }
    int max = 0;
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        int result = dfs(i);
        if (result > max) {
            max = result;
            pos = i;
        }
    }
    while (pos != -1) {
        cout<<pos<<" ";
        pos = nexts[pos];
    }
    printf("\n%d", max);
}