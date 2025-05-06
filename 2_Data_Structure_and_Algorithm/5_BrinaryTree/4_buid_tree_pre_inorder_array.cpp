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
void inOrderTraverse(TreeNode *&root){
    if(root == NULL){
        return;
    }
    inOrderTraverse(root->left);
    cout<<root->val<<" ";
    inOrderTraverse(root->right);
}

//create function



int linearSearch(int *arr,int start,int end,int key){
    for (int i = start; i <= end; ++i) {
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

TreeNode* buildTreePreInorderArray(int *preOrder,int *inorder,int start,int end){
    if(start > end){
        return NULL;
    }
    static int i=0;
    int element = preOrder[i];
    i++;

    TreeNode *temp = new TreeNode(element);

    if(start == end){
        return temp;
    }

    int pos = linearSearch(inorder,start,end,element);
    temp->left = buildTreePreInorderArray(preOrder,inorder,start,pos-1);
    temp->right = buildTreePreInorderArray(preOrder,inorder,pos+1,end);
    return temp;
}

int main(){
    int preOrder[] = {3, 1, 13, 5, 6, 10, 11, 16, 15, 9, 4, 2};
    int inorder[] = {13, 1, 6, 5, 3, 11, 10, 9 ,15, 4, 16, 2};
    int n=12;

    TreeNode *root = buildTreePreInorderArray(preOrder,inorder,0,n-1);
    inOrderTraverse(root);

}