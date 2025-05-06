#include "iostream"
#include "queue"
#include "vector"
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

vector<TreeNode*> constructAllPossibleTrees(int startNumber,int endNumber){
    vector<TreeNode*> trees;

    for (int ithNumber = startNumber; ithNumber <= endNumber ; ++ithNumber) {
        vector<TreeNode*> leftSubTrees = constructAllPossibleTrees(startNumber,ithNumber);
        vector<TreeNode*> rightSubTrees = constructAllPossibleTrees(ithNumber,endNumber);

        for (int a = 0; a < leftSubTrees.size(); ++a) {
            TreeNode *ithLeftSubTree = leftSubTrees[a];
            for (int b = 0; b < rightSubTrees.size(); ++b) {
                TreeNode *ithRightSubTree = rightSubTrees[b];

                TreeNode *ithNode = new TreeNode(ithNumber);
                ithNode->left = ithLeftSubTree;
                ithNode->right = ithRightSubTree;

                trees.push_back(ithNode);
            }
        }
    }
    return trees;
}


int main(){
    vector<TreeNode*> tress = constructAllPossibleTrees(1,3);
    for (int i = 0; i < tress.size(); ++i) {
        cout<<i+1<<":";
        levelOrderPrint(tress[i]);
        cout<<endl;
    }

}