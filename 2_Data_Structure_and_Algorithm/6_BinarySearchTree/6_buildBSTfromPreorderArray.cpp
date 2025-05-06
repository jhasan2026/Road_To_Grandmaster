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

TreeNode* minFinder(TreeNode *&root){
    while (root->left != NULL){
        root = root->left;
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


// Create BST Function

TreeNode* buildBSTfromPreorderArray(int *preorder,int *preIdx,int element,int minVal,int maxVal,int n){
      if(*preIdx > n){                  //array size bound :: return NULL
          return NULL;
      }

      TreeNode *root = NULL;
      if(element > minVal && element<maxVal){           //if false :: doest not maintain BST rules (node must be less than minVal and greater than maxVal)
          root = new TreeNode(element);             // creating node
          (*preIdx) = (*preIdx) +1;                     //increasing index

          if((*preIdx) <n){                             //If index less than size::
              root->left = buildBSTfromPreorderArray(preorder,preIdx,preorder[*preIdx],minVal,element,n);       //construct (min <--> element)
          }

          if((*preIdx) <n){
              root->right = buildBSTfromPreorderArray(preorder,preIdx,preorder[*preIdx],element,maxVal,n);      //construct (element<-->max)
          }
      }
    return root;

}


int main(){
    TreeNode *root;
//    root = insertInBST(root,8);
//    root = insertInBST(root,10);
//    root = insertInBST(root,3);
//    root = insertInBST(root,6);
//    root = insertInBST(root,4);
//    root = insertInBST(root,14);
//    root = insertInBST(root,1);
//    root = insertInBST(root,7);
//    root = insertInBST(root,13);

    int preIndex=0;
    int preArray[]={8,3,1,6,4,7,10,14,13};
    root = buildBSTfromPreorderArray(preArray,&preIndex,preArray[preIndex],INT_MIN,INT_MAX,9);


    levelOrderPrint(root);


}