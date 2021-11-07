#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int x, int size) {
    if (x < 0) {
        return false;
    }
    if (size == 1 || size == 0) {
        return true;
    }
    int last = x % 10;
    int first=x/ (int)pow(10.0, size-1);
    if (first!=last){
        return false;
    }
    return isPalindrome((x/10)- ((int)pow(10.0, size-2)*first), size - 2);
}

bool isPalindrome(int x) {
    int count=0;
    int y=x;
    while (y!=0){
        count++;
        y/=10;
    }
    return isPalindrome(x,count);
}

int main(){
    bool result=isPalindrome(1245);
    cout<<result<<endl;
}