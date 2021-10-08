#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
 *给你一个字符串 path ，
 *表示指向某一文件或目录的 Unix 风格 绝对路径(以 '/' 开头)，
 *请你将其转化为更加简洁的规范路径。
 *请注意，返回的 规范路径 必须遵循下述格式：
 *始终以斜杠 '/' 开头。
 *两个目录名之间必须只有一个斜杠 '/' 。
 *最后一个目录名（如果存在）不能 以 '/' 结尾。
 *此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
*/
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