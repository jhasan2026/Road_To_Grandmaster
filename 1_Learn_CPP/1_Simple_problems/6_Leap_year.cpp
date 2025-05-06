#include "iostream"

using namespace std;

bool isLeapYear(int n){
    if(n % 400 == 0){
        return true;
    }
    else{
        if(n%4==0 && n%100!=0){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    cout<<isLeapYear(2024);
}