#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> cache;
    if (nums.size() < 3) {
        return result;
    }
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            break;
        }
        while (i>=1&&i<nums.size()){
            if (nums[i]==nums[i-1]){
                i++;
            }else{
                break;
            }
        }
        left = i + 1;
        right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] + nums[i] == 0) {
                cache.push_back(nums[i]);
                cache.push_back(nums[left]);
                cache.push_back(nums[right]);
                result.push_back(cache);
                cache.clear();
                left++;
                while (left<right){
                    if (nums[left]==nums[left-1]){
                        left++;
                    }else{
                        break;
                    }
                }
            } else if (nums[left] + nums[right] + nums[i] < 0) {
                left++;
                while (left<right){
                    if (nums[left]==nums[left-1]){
                        left++;
                    }else{
                        break;
                    }
                }
            } else if (nums[left] + nums[right] + nums[i] > 0) {
                right--;
                while (left<right){
                    if (nums[right]==nums[right+1]){
                        right--;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    cout<<result[0][0]<<endl;
}

