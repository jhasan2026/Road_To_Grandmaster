#include "iostream"
#include "queue"
#include "stack"
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

void levelOrderPrint(TreeNode *root,stack<TreeNode*> &st){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        TreeNode *frontNode = q.front();
        q.pop();

        if(frontNode != NULL){
            st.push(frontNode);

            if(frontNode->right != NULL){
                q.push(frontNode->right);
                st.push(frontNode->right);
            }
            if(frontNode->left != NULL){
                q.push(frontNode->left);
                st.push(frontNode->left);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            st.push(NULL);
        }

    }
}
void reverseLevelOrderPrint(TreeNode *root){
    stack<TreeNode*> st;
    levelOrderPrint(root,st);
    while (!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        if(node != NULL){
            cout<<node->val<<" ";
        }
        else{
            cout<<endl;
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

    reverseLevelOrderPrint(root);
}