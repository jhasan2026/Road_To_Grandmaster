#include "iostream"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
    TreeNode(int val,TreeNode *left,TreeNode *right){
        this->val = val;
        this->left = left;
        this->right = right;
        this->parent = NULL;
    }
};

TreeNode* insertInBST(TreeNode *&root,int node){
    if(root == NULL){
        return new TreeNode(node);
    }

    TreeNode *findData = NULL;
    if(node < root->val){
        findData = insertInBST(root->left,node);
        root->left = findData;
        findData->parent = root;
    }
    else{
        findData = insertInBST(root->right,node);
        root->right = findData;
        findData->parent = root;
    }
    return root;
}

bool checkValidBST(TreeNode *root,TreeNode *minNode,TreeNode *maxNode){
    if(root == NULL){           // empty tree is valanced
        return true;
    }
    if(minNode != NULL && root->val <= minNode->val){           //if root data is greater than minNode
        return false;
    }
    if(maxNode != NULL && root->val >= maxNode->val){           //if root data is less than maxNode
        return false;
    }

    bool leftValidity = checkValidBST(root->left,minNode,root);         //check validity for left tree::(min<--->key)
    bool rightValidity = checkValidBST(root->right,root,maxNode);       //check validity for right tree::(key<--->max)
    return leftValidity && rightValidity;
}


int main() {
    TreeNode *root = NULL;
    root = insertInBST(root,8);
    root = insertInBST(root,10);
    root = insertInBST(root,3);
    root = insertInBST(root,6);
    root = insertInBST(root,4);
    root = insertInBST(root,14);
    root = insertInBST(root,1);
    root = insertInBST(root,7);
    root = insertInBST(root,13);
    cout<<checkValidBST(root,NULL,NULL);

}