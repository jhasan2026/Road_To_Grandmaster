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

void printKthDistanceSubTree(TreeNode *&root,int k){
    if(root == NULL || k<0){
        return;
    }
    if(k == 0){
        cout<<root->val<<" ";
    }
    printKthDistanceSubTree(root->left,k-1);
    printKthDistanceSubTree(root->right,k-1);
}

int kthDistanceFromBase(TreeNode *&root,int base,int k){
    if(root == NULL){
        return -1;
    }
    if(root->val == base){
        printKthDistanceSubTree(root,k);
        return 0;
    }

    int leftAncestorDistance = kthDistanceFromBase(root->left,base,k);
    if(leftAncestorDistance != -1){
        if(leftAncestorDistance+1 == k){
            cout<<root->val<<" ";
        }
        else{
            printKthDistanceSubTree(root->right,k-2-leftAncestorDistance);
        }
        return 1 + leftAncestorDistance;
    }
    int rightAncestorDistance = kthDistanceFromBase(root->right,base,k);
    if(rightAncestorDistance != -1){
        if(rightAncestorDistance+1 == k){
            cout<<root->val<<" ";
        }
        else{
            printKthDistanceSubTree(root->left,k-2-rightAncestorDistance);
        }
        return 1 + rightAncestorDistance;
    }
    return -1;
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
    kthDistanceFromBase(root,10,2);

}