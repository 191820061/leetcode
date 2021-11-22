#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4) {
        return result;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        while (i > 0 && nums[i] == nums[i - 1] && i < nums.size()) {
            i++;
        }
        if (i>nums.size()||nums[i] > target) {
            break;
        }
        for (int j = i + 1; j < nums.size(); j++) {
            while (j > i + 1 && nums[j] == nums[j - 1] && j < nums.size()) {
                j++;
            }
            if (j>nums.size()) {
                break;
            }
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right) {
                long add = nums[i] + nums[j] + nums[left] + nums[right];
                if (add == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    while (left < right) {
                        if (nums[left] == nums[left - 1]) {
                            left++;
                        }else{
                            break;
                        }
                    }
                } else if (add < target) {
                    left++;
                    while (left < right) {
                        if (nums[left] == nums[left - 1]) {
                            left++;
                        }else{
                            break;
                        }
                    }
                } else {
                    right--;
                    while (left < right) {
                        if (nums[right] == nums[right + 1]) {
                            right--;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums{0,0,0,0};
    cout<<fourSum(nums,0)[0][0];
}