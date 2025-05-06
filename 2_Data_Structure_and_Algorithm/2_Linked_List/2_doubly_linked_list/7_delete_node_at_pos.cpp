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

void deleteNodeAtPosDoubly(ListNode *&head,int pos){
    if(pos==1 || head->next == NULL){
        deleteFirstNodeDoubly(head);
        return;
    }
    pos--;
    ListNode *ptr = head;
    while (pos != 1 ){
        pos--;
        ptr = ptr->next;
        if(ptr->next->next == NULL){
            ListNode *lastNode = ptr->next;
            ptr->next = NULL;
            delete(lastNode);
            return;
        }
    }
    ListNode *ptr2 = ptr->next;
    ptr->next = ptr2->next;
    ptr2->next->prev = ptr;
    delete(ptr2);
}



int main(){
//    ListNode *head = NULL;
    ListNode *head = createFirstNode(5);
    addNodeAtEndDoubly(head,7);
    addNodeAtEndDoubly(head,33);
    addNodeAtEndDoubly(head,42);

    deleteNodeAtPosDoubly(head,1);

    printDoublyLinkedList(head);
}