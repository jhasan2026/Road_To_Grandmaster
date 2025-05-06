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



int calDiameter(TreeNode *root,int *height){
    if(root==NULL){
        return 0;
    }

    int leftHeight=0,rightHeight=0;
    int leftDiameter= calDiameter(root->left,&leftHeight);          //calculate left diameter
    int rightDiameter= calDiameter(root->right,&rightHeight);           //calculate right diameter

    int diameterByRoot=leftHeight+rightHeight+1;                //diameter goes through root is left and right hight and (1 for root)
    *height=max(leftHeight,rightHeight)+1;

    return max(diameterByRoot, max(leftDiameter,rightDiameter));
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
    calDiameter(root,&height);
    cout<<height;
}