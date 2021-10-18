#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int area;
    int maxA = 0;
    while (left<right){
        if (height[left]<=height[right]){
            area=(right-left)*height[left];
            left++;
        }else{
            area=(right-left)*height[right];
            right--;
        }
        if (area>maxA){
            maxA=area;
        }
    }

    return maxA;
}

int main(int argc, char *argv[]) {
    vector<int> v = {1,2,1};
    cout << maxArea(v) << endl;
}
