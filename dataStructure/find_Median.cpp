#include <iostream>
#include <vector>

using namespace std;

int find_K(vector<int> &nums1, vector<int> &nums2, int k) {
    int left = 0;
    int right = 0;
    int count = 0;
    while (left != nums1.size() && right != nums2.size()) {
        if (nums1[left] <= nums2[right]) {
            count++;
            if (count==k){
                return nums1[left];
            }
            left++;
        }else{
            count++;
            if (count==k){
                return nums2[right];
            }
            right++;
        }
    }
    if (left==nums1.size()){
        while (right != nums2.size()){
            count++;
            if (count==k){
                return nums2[right];
            }
            right++;
        }
    }else if (right== nums2.size()){
        while (left != nums1.size()){
            count++;
            if (count==k){
                return nums1[left];
            }
            left++;
        }
    }
    return -1;
}



double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if ((nums1.size() + nums2.size()) % 2 == 1) {
        return find_K(nums1, nums2, ((int) nums1.size() + (int) nums2.size()) / 2 + 1);
    } else {
        return (find_K(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
                find_K(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1))/2.0;
    }
}

int main() {
    vector<int> num1{1,2};
    vector<int> num2{3,4};
    cout<<findMedianSortedArrays(num1,num2)<<endl;
}