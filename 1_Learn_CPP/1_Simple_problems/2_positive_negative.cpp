#include "iostream"

using namespace std;

void isPostive(int n){
    if(n>0){
        cout<<"Positive"<<endl;
    }
    else if(n<0){
        cout<<"Negative"<<endl;
    }
    else{
        cout<<"Zero"<<endl;
    }
}

int main(){
    isPostive(8);
}