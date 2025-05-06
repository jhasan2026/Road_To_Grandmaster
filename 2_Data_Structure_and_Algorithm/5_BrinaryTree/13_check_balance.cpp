#include "iostream"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val,TreeNode *left,TreeNode *right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};
int heightOfTree(TreeNode *&root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return 1 + max(leftHeight,rightHeight);
}

bool checkIsBalanced(TreeNode *root,int *height){
    if(root==NULL){
        return true;
    }
    int leftHeiPtr=0,rightHeiPtr=0;
    if(checkIsBalanced(root->left,&leftHeiPtr)== false){         //if any time left subtree is not balanced so the whole tree is not balanced
        return false;
    }
    if(checkIsBalanced(root->right,&rightHeiPtr)== false){
        return false;
    }
    *height=max(leftHeiPtr,rightHeiPtr)+1;                  //find height
    if(abs(leftHeiPtr-rightHeiPtr)<=1){                    //diff between left and right tree is <=1
        return true;
    }
    else {
        return false;
    }
}


int main(){
    TreeNode *root = NULL;
    root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(13);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);

    root->right = new TreeNode(10);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(16);
    root->right->right->left = new TreeNode(15);
    root->right->right->right = new TreeNode(2);
    root->right->right->left->left = new TreeNode(9);
    root->right->right->left->right = new TreeNode(4);

    int height = 0;
    cout<<checkIsBalanced(root,&height);
}