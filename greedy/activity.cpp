#include <iostream>
#include <algorithm>

using namespace std;

struct activity {
    int begin_time;
    int end_time;
};

activity all[3000000];
int n;

bool cmp(activity a, activity b) {
    return a.end_time < b.end_time;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> all[i].begin_time >> all[i].end_time;
    }
    sort(all + 1, all + 1 + n, cmp);
    int m = 1;
    int end = all[1].end_time;
    for (int i = 2; i <= n; i++) {
        if (all[i].begin_time >= end) {
            end = all[i].end_time;
            m++;
        }
    }
    cout << m << endl;
}