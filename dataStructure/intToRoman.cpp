#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void get_string(string &result, int value) {
    if (value==0){
        return;
    }
    if (value>=1000){
        result+="M";
        return get_string(result,value-1000);
    }else if(value>=500){
        result+="D";
        return get_string(result,value-500);
    }else if(value>=100){
        result+="C";
        return get_string(result,value-100);
    } else if(value>=50){
        result+="L";
        return get_string(result,value-50);
    }else if(value>=10){
        result+="X";
        return get_string(result,value-10);
    }else if(value>=5){
        result+="V";
        return get_string(result,value-5);
    }else if(value>=1){
        result+="I";
        return get_string(result,value-1);
    }
}

string intToRoman(string &result, int x, int size) {
    if (size == 0) {
        return result;
    }
    int first_num = x / (int) pow(10.0, size - 1);
    int first_value = (int) pow(10.0, size - 1) * first_num;
    if (first_value == 4) {
        result += "IV";
    } else if (first_value == 9) {
        result += "IX";
    } else if (first_value == 40) {
        result += "XL";
    } else if (first_value == 90) {
        result += "XC";
    } else if (first_value == 400) {
        result += "CD";
    } else if (first_value == 900) {
        result += "CM";
    } else {
        get_string(result, first_value);
    }
    return intToRoman(result, x - first_value, size - 1);
}

string intToRoman(int x) {
    int count=0;
    int y=x;
    while (y!=0){
        count++;
        y/=10;
    }
    string result;
    return intToRoman(result,x,count);
}

int main() {
    cout<<intToRoman(1994)<<endl;
}