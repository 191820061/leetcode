#include <iostream>
using namespace std;
int reverse(int x) {
    int num;
    while (x!=0){
        if (num>INT_MAX/10||num<INT_MIN/10){
            return 0;
        }
        num=num*10+x%10;
        x/=10;
    }
    return num;
}

int main(){
    cout<<reverse(-2147483412)<<endl;
}