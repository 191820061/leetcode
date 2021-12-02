#include <iostream>

using namespace std;

struct LineSeg {
    int begin;
    int end;
};

int n;
LineSeg line[30000];
int dp[30000][2];


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> line[i].begin >> line[i].end;
    }
    dp[1][0] = 2 * line[1].end - line[1].begin;
    dp[1][1] = line[1].end - 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0] + 1 + abs(line[i - 1].begin - line[i].end) + line[i].end - line[i].begin,
                       dp[i - 1][1] + 1 + abs(line[i - 1].end - line[i].end) + line[i].end - line[i].begin);
        dp[i][1] = min(dp[i - 1][0] + 1 + abs(line[i - 1].begin - line[i].begin) + line[i].end - line[i].begin,
                       dp[i - 1][1] + 1 + abs(line[i - 1].end - line[i].begin) + line[i].end - line[i].begin);
    }
    cout << min(n - line[n].begin + dp[n][0], n - line[n].end + dp[n][1]) << endl;
}