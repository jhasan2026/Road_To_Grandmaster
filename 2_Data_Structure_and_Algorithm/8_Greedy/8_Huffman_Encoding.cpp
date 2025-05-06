#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class cmpp{
public:
    bool operator()(Node *a,Node *b){
        return a->data > b->data;
    }
};

void traverse(Node *root, vector<string > &ans,string temp){
    if(root->left==NULL && root->right==NULL){
        ans.push_back(temp);
        return;
    }
    traverse(root->left,ans,temp+'0');
    traverse(root->right,ans,temp+'1');

}
vector<string> huffmanEncoding(string str,vector<int> freq,int n){
    priority_queue<Node* ,vector<Node*>, cmpp> pq;

    for (int i = 0; i < n; ++i) {
        Node *temp=new Node(freq[i]);
        pq.push(temp);
    }

    while (pq.size() > 1){
        Node *left=pq.top();
        pq.pop();

        Node *right=pq.top();
        pq.pop();

        Node *newNode =new Node(left->data+right->data);

        newNode->left=left;
        newNode->right=right;

        pq.push(newNode);
    }

    Node *root=pq.top();

    vector<string > ans;
    string temp="";
    traverse(root,ans,temp);
    return ans;
}


int main(){
    string str="abcdef";
    vector<int> f={5,9,12,13,16,45};
    vector<string > ans= huffmanEncoding(str,f,6);
    for (auto x:ans) {
        cout<<x<<endl;
    }
    break;
}