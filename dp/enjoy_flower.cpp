#include <bits/stdc++.h>

using namespace std;

int times;
int n;
int count_time[10010];
int tree_value[10010];
int tree_count[10010];
int dp[10010][1000];

int string_to_date(string &time) {
    int hour = 0;
    int minute = 0;
    bool isHour = true;
    for (char i: time) {
        if (i == ':') {
            isHour = false;
            continue;
        }
        if (isHour) {
            hour = hour * 10 + (i - '0');
        } else {
            minute = minute * 10 + (i - '0');
        }
    }
    return hour * 60 + minute;
}

void set_times(string &begin, string &end) {
    int begin_time = string_to_date(begin);
    int end_time = string_to_date(end);
    if (end_time < begin_time) {
        times = 24 * 60 - begin_time + end_time;
    } else {
        times = end_time - begin_time;
    }
}

int main() {
    string begin;
    string end;
    cin >> begin >> end;
    set_times(begin, end);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> count_time[i];
        cin >> tree_value[i];
        cin >> tree_count[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= times; j++) {
            dp[i][j] = dp[i - 1][j];
            if (count_time[i] <= j) {
                if (tree_count[i] == 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - count_time[i]] + tree_value[i]);
                } else {
                    for (int k = 1; k <=tree_count[i]&&j-k*count_time[i]>=0; k++) {
                        dp[i][j] = max(dp[i][j],dp[i - 1][j - k * count_time[i]] + k * tree_value[i]);
                    }
                }
            }
        }
    }
    cout<<dp[n][times]<<endl;
}