#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool cmp(string& a,string& b) {
    return a+b>b+a;
}

void sorted(vector<string> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 1; j < nums.size(); j++) {
            if (cmp(nums[j],nums[j-1])) {
                string a = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = a;
            }
        }
    }
}

int main() {
    int n;
    vector<string> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string element;
        cin >> element;
        nums.push_back(element);
    }
    sorted(nums);
    string result;
    for (auto &num: nums) {
        result += num;
    }
    cout << result << endl;

}