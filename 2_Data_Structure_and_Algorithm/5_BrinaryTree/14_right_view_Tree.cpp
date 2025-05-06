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

void rightViewOfTree(TreeNode *&root){
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){

        int widthOfLevel = q.size();

        for (int i = 0; i < widthOfLevel; ++i) {
            TreeNode *frontNode = q.front();
            q.pop();

            if(frontNode != NULL){
                if(i == widthOfLevel-1) {
                    cout << frontNode->val << " ";
                }
                if(frontNode->left != NULL){
                    q.push(frontNode->left);
                }

                if(frontNode->right != NULL){
                    q.push(frontNode->right);
                }
            }
        }
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

    rightViewOfTree(root);
}