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

int main(){
    Node *poly = NULL;
    insertPolynomial(poly,5.1,2);
    insertPolynomial(poly,3.6,1);
    insertPolynomial(poly,2,0);
    printPolynomial(poly);
}