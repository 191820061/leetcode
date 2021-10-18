#include <iostream>
#include <vector>
using namespace std;

/**
 * Given n non-negative integers a1, a2, ..., an ,
 * where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints
 * of the line i is at (i, ai) and (i, 0). Find two lines,
 * which, together with the x-axis forms a container, such
 * that the container contains the most water.
 * Notice that you may not slant the container.
 * */
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
