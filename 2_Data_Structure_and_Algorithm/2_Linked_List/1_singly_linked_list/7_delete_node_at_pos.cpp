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

//Now Create function


void deleteNodeAtPos(ListNode *&head,int pos){
    if(head == NULL || pos==0){
        return;
    }
    if(pos == 1){
        ListNode *trash =head;
        head = head->next;
        delete(trash);
        return;
    }
    ListNode *ptr = head;
    pos--;
    while (pos != 1){
        ptr = ptr->next;
        pos--;
    }
    ListNode *trash = ptr->next;
    ptr->next = ptr->next->next;
    delete(trash);

}

int main(){
    ListNode *head = createFirstNode(5);
    addNodeAtEnd(head,89);
    addNodeAtEnd(head,12);
    addNodeAtEnd(head,18);
    addNodeAtEnd(head,57);
    addNodeAtEnd(head,46);
    deleteNodeAtPos(head,2);
    printLinkedList(head);
}