#include <iostream>
#include <stack>
#include <string>
using namespace std;

string convertToSpe(string& s) {
	int n = s.size();
	int i = 0;
	stack<string> stk;
	int array[2000] = { 0 };
	int index = 0;
	int j = 0;
	string substr;
	string result;
	while (i < n) {
		if (s[i] == '/') {
			array[index++] = i;
		}
		i++;
	}
	
	while (j < index) {
		if (j + 1 != index && array[j + 1] - array[j] != 1) {
			substr = s.substr(array[j] + 1, array[j+1]-array[j]-1);
			if (substr == ".." && !stk.empty()) {
				stk.pop();
			}
			else if (substr != "."&&substr!="..") {
				stk.push(substr);
			}
		}
		else if (j + 1 == index) {
			if (array[j] + 1 != n) {
				substr = s.substr(array[j] + 1, n-i-1);
				if (substr == ".." && !stk.empty()) {
					stk.pop();
				}
				else if (substr != "." && substr != "..") {
					stk.push(substr);
				}
			}
		}
		j++;
	}
	if (stk.empty()) {
		return string("/");
	}
	while (!stk.empty()) {
		result = "/"+stk.top() + result;
		stk.pop();
	}
	return result;
}

int main(int argc, char* argv[]) {
	string path;
	cin >> path;
	cout << convertToSpe(path) << endl;
}