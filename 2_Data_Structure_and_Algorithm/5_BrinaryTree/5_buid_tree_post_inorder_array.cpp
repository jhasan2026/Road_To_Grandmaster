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

TreeNode* buildTreePostInorderArray(int *postOrder,int *inorder,int start,int end){
    if(start > end){
        return NULL;
    }
    static int i=end-1;
    int element = postOrder[i];
    i--;

    TreeNode *temp = new TreeNode(element);

    if(start == end){
        return temp;
    }

    int pos = linearSearch(inorder,start,end,element);
    temp->right = buildTreePostInorderArray(postOrder,inorder,pos+1,end);
    temp->left = buildTreePostInorderArray(postOrder,inorder,start,pos-1);
    return temp;
}

int main(){
    int postOrder[] = {13, 6, 5, 1, 11, 9, 4, 15, 2, 16, 10, 3};
    int inorder[] = {13, 1, 6, 5, 3, 11, 10, 9 ,15, 4, 16, 2};
    int n=12;

    TreeNode *root = buildTreePostInorderArray(postOrder,inorder,0,n-1);
    inOrderTraverse(root);

}