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

TreeNode* lowestCommonAncestor(TreeNode *&root,int node1,int node2){
    if(root == NULL){
        return NULL;
    }

    if(root->val == node1 || root->val == node2){
        return root;
    }
    TreeNode *leftSearch = lowestCommonAncestor(root->left,node1,node2);
    TreeNode *rightSearch = lowestCommonAncestor(root->right,node1,node2);

    if(leftSearch != NULL && rightSearch != NULL){
        return root;
    }

    if(leftSearch==NULL && rightSearch==NULL){
        return NULL;
    }
    if(leftSearch != NULL){
        return lowestCommonAncestor(root->left,node1,node2);
    }
    return lowestCommonAncestor(root->right,node1,node2);

}
int distanceBetweenNodeToRoot(TreeNode *&root,int node,int distance){
    if(root == NULL){
        return -1;
    }
    if(root->val == node){
        return distance;
    }
    int leftDistance = distanceBetweenNodeToRoot(root->left,node,distance+1);
    if(leftDistance != -1){
        return leftDistance;
    }
    return distanceBetweenNodeToRoot(root->right,node,distance+1);
}


int distanceBetweenTwoNode(TreeNode *&root,int node1,int node2){
    TreeNode *LCA = lowestCommonAncestor(root,node1,node2);
    int node1Distance = distanceBetweenNodeToRoot(LCA,node1,0);
    int node2Distance = distanceBetweenNodeToRoot(LCA,node2,0);
    return node1Distance + node2Distance;
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
    cout<<distanceBetweenTwoNode(root,6,4);

}