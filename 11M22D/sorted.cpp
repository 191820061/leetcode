#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<int> a;
    int ele;
    for (int i = 0; i < m; i++) {
        cin >> ele;
        a.push_back(ele);
    }

    sort(a.begin(),a.end());
    for (int i = 0; i < m; i++) {
        cout<< a[i]<<" ";
    }
    return 0;
}