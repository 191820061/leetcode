#include <iostream>
#include "Tree.h"
#include <vector>

using namespace std;

vector<TreeNode<int> *> generateTrees(int begin, int end) {
    vector<TreeNode<int> *> res;
    if (begin >= end) {
        res.push_back((begin==end?new TreeNode<int>(begin):nullptr));
    } else if (begin < end) {
        for (int i=begin;i<=end;i++){
            vector<TreeNode<int> *> leftTrees= generateTrees(begin,i-1);
            vector<TreeNode<int> *> rightTrees= generateTrees(i+1,end);
            for (TreeNode<int> *leftTree:leftTrees ){
                for (TreeNode<int> *rightTree:rightTrees){
                    res.push_back(new TreeNode<int>(i,leftTree,rightTree));
                }
            }
        }
    }
    return res;
}

vector<TreeNode<int> *> generateTrees(int n) {
    return generateTrees(1, n);
}

int numTrees(int n) {
    return (int)generateTrees(n).size();
}

int main() {
    int n;
    cin >> n;
    cout<<numTrees(n);

}