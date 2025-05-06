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


// Create function

int searchElement(ListNode *&head,int key){
    ListNode *ptr=head;
    int i=0;
    while (ptr!=NULL){
        if(ptr->val == key){
            return i;
        }
        ptr=ptr->next;
        i++;
    }
    return -1;
}

int main(){
    ListNode *head = createFirstNode(5);
    addNodeAtEnd(head,89);
    addNodeAtEnd(head,12);
    addNodeAtEnd(head,18);
    addNodeAtEnd(head,57);
    addNodeAtEnd(head,46);
    cout<<searchElement(head,46);

}