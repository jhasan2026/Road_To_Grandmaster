#include "iostream"

using namespace std;

struct Node{
    double coef;
    int expo;
    Node *next;
    Node(double coef,int expo){
        this->coef = coef;
        this->expo = expo;
        this->next = NULL;
    }
};

void insertPolynomial(Node *&head,double co,int ex){
    Node *newNode = new Node(co,ex);
    if(head == NULL || head->expo < ex){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *ptr = head;
    while (ptr->next != NULL){
        if(ptr->expo == ex){
            (ptr->coef) += co;
        }
        else if(ptr->expo > ex && ptr->next->expo < ex){
            newNode->next = ptr->next;
            ptr->next = newNode;
            return;
        }
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        if(ptr->expo == ex){
            (ptr->coef) += co;
        }
        else{
            ptr->next = newNode;
        }
    }
}

void printPolynomial(Node *&head){
    if(head == NULL){
        cout<<"Polynomial is empty";
        return;
    }
    Node *ptr=head;
    while (ptr!=NULL){
        cout<<"("<<ptr->coef<<" X^"<<ptr->expo<<") ";
        if(ptr->next!=NULL){
            cout<<"+ ";
        }
        ptr=ptr->next;
    }
    cout<<endl;
}


//------------------------------------------------------

Node* addTwoPolynomial(Node *&head1, Node *&head2){
    Node *ptr1 = head1;
    Node *ptr2 = head1;

    Node *head = NULL;

    while (ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo == ptr2->expo){
            insertPolynomial(head,ptr1->coef + ptr2->coef,ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo){
            insertPolynomial(head,ptr1->coef,ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo){
            insertPolynomial(head,ptr2->coef,ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1!=NULL){
        insertPolynomial(head,ptr1->coef,ptr1->expo);
        ptr1=ptr1->next;
    }
    while (ptr2!=NULL){
        insertPolynomial(head,ptr2->coef,ptr2->expo);
        ptr2=ptr2->next;
    }
    return head;
}

int main(){
    Node *poly1 = NULL;
    insertPolynomial(poly1,5.1,2);
    insertPolynomial(poly1,3.6,1);
    insertPolynomial(poly1,2,0);
    printPolynomial(poly1);

    Node *poly2 = NULL;
    insertPolynomial(poly2,2.1,2);
    insertPolynomial(poly2,1.6,1);
    insertPolynomial(poly2,1,0);
    printPolynomial(poly2);

    Node *sum = addTwoPolynomial(poly1,poly2);
    printPolynomial(sum);
}