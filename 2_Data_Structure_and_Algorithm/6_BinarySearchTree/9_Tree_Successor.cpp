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

TreeNode* searchInBST(TreeNode *&root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->val == key){
        return root;
    }
    if(key < root->val){
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}

TreeNode* minFinder(TreeNode *&root){
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

TreeNode* treeSuccessor(TreeNode *root,int base){
    TreeNode *temp = searchInBST(root,base);

    if(temp->right != NULL){
        return minFinder(temp->right);
    }

    TreeNode *parentFinder = temp->parent;
    while (parentFinder!=NULL && temp==parentFinder->right){
        temp = parentFinder;
        parentFinder = parentFinder->parent;
    }
    return parentFinder;
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
    cout<<treeSuccessor(root,7)->val;

}