#include <iostream>
#include <stack>
#include <vector>
using namespace  std;
/**
 * 根据 逆波兰表示法，求表达式的值。
 * 有效的算符包括+、-、*、/。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 * 说明：
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 * */

/**
 * if the string is a number return true else return false
 * */
bool digit(string &x) {
    if (x.size() >= 2) {
        return true;
    }
    return isdigit(x[0]);
}

int evalRPN(vector <string> &tokens) {
    int n = tokens.size();
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (digit(tokens[i])) {
            stk.push(stoi(tokens[i]));
        } else {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
            int result;
            if (tokens[i] == "+") {
                result = num1 + num2;
            } else if (tokens[i] == "-") {
                result = num2 - num1;
            } else if (tokens[i] == "*") {
                result = num2 * num1;
            } else {
                result = num2 / num1;
            }
            stk.push(result);
        }
    }
    return stk.top();
}

/**
 * test the evalRPN function
 * */
int main(){
    vector<string> v={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(v)<<endl;
}