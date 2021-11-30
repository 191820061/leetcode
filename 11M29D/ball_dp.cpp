#include <iostream>

using namespace std;

int n;
int m;
int meb[60][60];

int main() {
    cin >> n >> m;
    meb[0][1] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int left = j - 1;
            int right = j % n + 1;
            if (left == 0) {
                left = n;
            }
            meb[i][j] = meb[i - 1][left] + meb[i - 1][right];
        }
    }
    cout<<meb[m][1]<<endl;
}