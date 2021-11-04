#include <iostream>
#include "Tree.h"
using namespace std;

bool isSameTree(TreeNode<int>* p, TreeNode<int>* q){
    if (p== nullptr&&q== nullptr){
        return true;
    }else if(p== nullptr||q== nullptr){
        return false;
    }else if (p->item!=q->item){
        return false;
    }else{
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
}
int main(){

}