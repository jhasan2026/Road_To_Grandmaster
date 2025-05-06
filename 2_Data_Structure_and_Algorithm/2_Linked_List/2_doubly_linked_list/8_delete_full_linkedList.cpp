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

void deleteFirstNodeDoubly(ListNode *&head){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        delete(head);
        head = NULL;
        return;
    }
    ListNode *temp = head->next;
    temp->prev =NULL;
    delete(head);
    head = temp;
}

//----------------------------------------------------------------------


void deleteFullLinkedListDoubly(ListNode *&head) {
    while (head != NULL) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}



int main(){
//    ListNode *head = NULL;
    ListNode *head = createFirstNode(5);
    addNodeAtEndDoubly(head,7);
    addNodeAtEndDoubly(head,33);
    addNodeAtEndDoubly(head,42);
    deleteFullLinkedListDoubly(head);



    printDoublyLinkedList(head);
}