#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int n;
    int k = 0;
    vector<int> a;
    scanf("%d %d", &n, &k);
    int ele;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ele);
        a.push_back(ele);
    }
    nth_element(a.begin(),a.begin()+k,a.end());
    cout << a[k];
}