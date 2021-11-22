#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find(vector<int> &nums, int a, int b) {
    vector<int> result;
    int left = 0;
    int right = 0;
    for (int i=0;i<nums.size();i++){

    }
}

int main() {
    int n;
    int a;
    int b;
    int c;
    cin >> n >> a >> b;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> c;
        nums.push_back(c);
    }
    if (n % 2 == 1) {
        cout << 0 << endl;
    } else {
        vector<int> result = find(nums, a, b);
        if (result.size() == n / 2) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

}