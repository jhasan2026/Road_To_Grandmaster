#include "iostream"

using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int data){
        this->val = data;
        this->next = NULL;
    }
    ListNode(int data,ListNode *next){
        this->val = data;
        this->next = next;
    }
};

ListNode* createFirstNode(int data){
    return new ListNode(data);
}

void printLinkedList(ListNode *&head){
    if(head == NULL){
        cout<<"Linked List is empty";
    }

    ListNode *ptr=head;
    while (ptr!=NULL){
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
}

int main(){
    ListNode *head = createFirstNode(5);
    printLinkedList(head);
}