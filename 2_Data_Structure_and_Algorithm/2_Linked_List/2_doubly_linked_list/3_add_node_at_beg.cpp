#include "iostream"

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

ListNode* createFirstNode(int data){
    return new ListNode(data);
}

void printDoublyLinkedList(ListNode *&head){
    if(head == NULL){
        cout<<"Linked list is null";
        return;
    }
    ListNode *ptr=head;
    while (ptr != NULL){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
}

void addNodeAtEndDoubly(ListNode *&head,int data){
    ListNode *ptr = head;
    while (ptr->next != NULL){
        ptr= ptr->next;
    }
    ListNode *newNode = new ListNode(data);
    newNode->prev = ptr;

    ptr->next = newNode;
}

//----------------------------------------------------------------------

void addNodeAtFirstDoubly(ListNode *&head,int data){
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}


int main(){
    ListNode *head = createFirstNode(5);
    addNodeAtEndDoubly(head,7);
    addNodeAtEndDoubly(head,33);
    addNodeAtEndDoubly(head,42);

    addNodeAtFirstDoubly(head,99);
    addNodeAtFirstDoubly(head,100);
    printDoublyLinkedList(head);
}