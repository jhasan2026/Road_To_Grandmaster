#include "iostream"

using namespace std;

void printEven(int x,int y){
    if(x>y){
        return;
    }
    if(x%2==0){
        cout<<x<<" ";
        printEven(x+2,y);
    }
    else{
        printEven(x+1,y);
    }
}

int main(){
    printEven(55,99);
}