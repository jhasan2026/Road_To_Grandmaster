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

int ascendingChecker(ListNode *&head){
    return head==NULL || head->next==NULL || (head->val < head->next->val && ascendingChecker(head->next));
}


int main(){
    ListNode *head = createFirstNode(5);
    addNodeAtEnd(head,9);
    addNodeAtEnd(head,12);
    addNodeAtEnd(head,18);
    addNodeAtEnd(head,57);
    addNodeAtEnd(head,96);
    cout<<ascendingChecker(head);

}