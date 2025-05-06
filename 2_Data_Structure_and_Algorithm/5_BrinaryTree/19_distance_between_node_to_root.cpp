#include "iostream"

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

int distanceBetweenNodeToRoot(TreeNode *&root,int node,int distance){
    if(root == NULL){
        return -1;
    }
    if(root->val == node){
        return distance;
    }
    int leftDistance = distanceBetweenNodeToRoot(root->left,node,distance+1);
    if(leftDistance != -1){
        return leftDistance;
    }
    return distanceBetweenNodeToRoot(root->right,node,distance+1);
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
    cout<<distanceBetweenNodeToRoot(root,9,0);

}