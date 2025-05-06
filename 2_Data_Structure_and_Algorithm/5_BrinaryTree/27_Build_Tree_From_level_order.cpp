#include "iostream"
#include "vector"
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

void buildFromLevelOrder(TreeNode *&root){
     queue<TreeNode*> q;

     int data;
     cout<<"Enter data:";
     cin>>data;
     root = new TreeNode(data);
     q.push(root);



    while (!q.empty()){
        TreeNode *temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<< root->val<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new TreeNode(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<< root->val<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new TreeNode(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    TreeNode *root = NULL;
    buildFromLevelOrder(root);
}