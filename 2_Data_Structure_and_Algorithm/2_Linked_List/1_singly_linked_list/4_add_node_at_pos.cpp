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

//Default function
ListNode* createFirstNode(int data){
    return new ListNode(data);
}
void addNodeAtEnd(ListNode *&head,int data){
    ListNode *ptr=head;
    while (ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next = new ListNode(data);
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


//Create now function
void addNodeAtPos(ListNode *&head,int data,int pos){
    ListNode *ptr=head;

    if(pos == 0){
        return;
    }
    if(pos==1){
        head = new ListNode(data,ptr);
        return;
    }

    pos--;
    while (pos!=1){
        ptr = ptr->next;
        pos--;
    }
    ListNode *temp = new ListNode(data,ptr->next);

    ptr->next = temp;

}

int main(){
    ListNode *head = createFirstNode(5);
    addNodeAtEnd(head,89);
    addNodeAtEnd(head,12);
    addNodeAtEnd(head,18);
    addNodeAtEnd(head,57);
    addNodeAtEnd(head,46);
    addNodeAtPos(head,100,1);
    printLinkedList(head);
}