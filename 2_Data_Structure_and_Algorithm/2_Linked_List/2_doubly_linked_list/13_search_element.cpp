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



void addNodeAtEndDoubly(ListNode *&head,int data){
    ListNode *ptr = head;
    while (ptr->next != NULL){
        ptr= ptr->next;
    }
    ListNode *newNode = new ListNode(data);
    newNode->prev = ptr;

    ptr->next = newNode;
}

//-----------------------------------------------

int searchElementDoubly(ListNode *&head,int srch){
    if(head == NULL){
        return -1;
    }
    int i = 0;
    ListNode *ptr=head;
    while (ptr != NULL){
        if(ptr->val == srch){
            return i;
        }
        i++;
        ptr = ptr->next;
    }
}




int main(){
//    ListNode *head = NULL;
    ListNode *head = createFirstNode(5);
    addNodeAtEndDoubly(head,7);
    addNodeAtEndDoubly(head,33);
    addNodeAtEndDoubly(head,42);


    cout<<searchElementDoubly(head,42);
}