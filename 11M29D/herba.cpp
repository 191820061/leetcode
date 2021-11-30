#include <iostream>

using namespace std;

int times;
int n;
int flower_time[20000];
int value[20000];
long long dp[20000000];

int main() {
    cin >> times >> n;
    for (int i = 1; i <= n; i++) {
        cin >> flower_time[i] >> value[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = flower_time[i]; j <= times; j++) {
            dp[j] = max(dp[j], dp[j - flower_time[i]] + value[i]);
        }
    }
    cout << dp[times] << endl;
}