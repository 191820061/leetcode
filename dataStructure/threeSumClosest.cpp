#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
    int min = INT_MAX;
    int min_add=0;
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = 0;
    for (int i = 0; i < nums.size(); i++) {
        left=i+1;
        right=nums.size()-1;
        while (left < right) {
            int add=nums[i] + nums[left] + nums[right];
            int result = add - target;
            if (abs(result) < min) {
                min = abs(result);
                min_add=add;
                if (min == 0) {
                    return add;
                }
            }
            if (add<target){
                left++;
            }else{
                right--;
            }
        }
    }
    return min_add;
}

int main() {
    vector<int> num{1,2,4,8,16,32,64,128};
    cout<<threeSumClosest(num,82)<<endl;
}