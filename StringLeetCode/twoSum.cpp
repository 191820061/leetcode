#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int findNum = target - nums[i];
        for (int j=i+1;j<n;j++){
            if (nums[j]==findNum){
                return vector<int>({i,j});
            }
        }
    }
    return vector<int>({0,0});
}

int main(int argc, char *argv[]) {
    vector<int> num({3, 2, 4});
    vector<int> result = twoSum(num, 6);
}