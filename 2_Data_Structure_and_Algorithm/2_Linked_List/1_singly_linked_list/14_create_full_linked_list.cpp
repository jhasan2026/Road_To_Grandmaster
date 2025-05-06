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

// Create function

ListNode* createLinkedList(){
    int size,data;
    cout<<"Size of list:";
    cin>>size;
    if(size==0){
        return NULL;
    }
    cout<<"Node 1:";
    cin>>data;
    ListNode *head= createFirstNode(data);
    for (int i = 2; i <= size; ++i) {
        cout<<"Node "<<i<<":";
        cin>>data;
        addNodeAtEnd(head,data);
    }
    return head;
}


int main(){
    ListNode *head = createLinkedList();


}

