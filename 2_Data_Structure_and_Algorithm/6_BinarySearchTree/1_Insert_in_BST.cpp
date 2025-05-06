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
void levelOrderPrint(TreeNode *&root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        TreeNode *frontNode = q.front();
        q.pop();

        if(frontNode != NULL){
            cout<<frontNode->val<<" ";
            if(frontNode->left != NULL){
                q.push(frontNode->left);
            }

            if(frontNode->right != NULL){
                q.push(frontNode->right);
            }
        }
        else if(!q.empty()){
            cout<<endl;
            q.push(NULL);
        }
    }
}

// Create BST function

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

int main(){
    TreeNode *root;
    root = insertInBST(root,8);
    root = insertInBST(root,10);
    root = insertInBST(root,3);
    root = insertInBST(root,6);
    root = insertInBST(root,4);
    root = insertInBST(root,14);
    root = insertInBST(root,1);
    root = insertInBST(root,7);
    root = insertInBST(root,13);
    levelOrderPrint(root);
}