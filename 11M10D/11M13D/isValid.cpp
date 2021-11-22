#include <iostream>
#include <deque>

using namespace std;

bool isValid(string s) {
    if (s.size()%2==1){
        return false;
    }
    deque<char> que;
    for (char c: s) {
        if (c == '(' || c == '{' || c == '[') {
            que.push_back(c);
        } else if(c==')') {
            if (que.empty()){
                return false;
            }
            char back=que.back();
            if (back=='('){
                que.pop_back();
            }else{
                return false;
            }
        }else if(c==']') {
            if (que.empty()){
                return false;
            }
            char back=que.back();
            if (back=='['){
                que.pop_back();
            }else{
                return false;
            }
        }else{
            if (que.empty()){
                return false;
            }
            char back=que.back();
            if (back=='{'){
                que.pop_back();
            }else{
                return false;
            }
        }
    }
    return que.empty();
}

int main(){
    string s="([}}])";
    cout<<isValid(s)<<endl;
}