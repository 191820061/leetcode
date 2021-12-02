
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int  main() {
    int n = 0;
    cin >> n;
    vector<int> a(n + 1, 0);
    int sum = 0, maxlen = 0, sum2 = 0;
    int u, v, w;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        a[v] = a[u] + w;
        sum += w * 2;
        maxlen = max(a[v], maxlen);
        sum2 += a[v];
    }
    cout << sum2 << " " << sum - maxlen;

}