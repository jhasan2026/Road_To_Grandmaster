#include "iostream"

using namespace std;

int findGCD(int x,int y){
    if(y==0){
        return x;
    }
    return findGCD(y,x%y);
}

int main(){
    cout<<findGCD(16,12);
}