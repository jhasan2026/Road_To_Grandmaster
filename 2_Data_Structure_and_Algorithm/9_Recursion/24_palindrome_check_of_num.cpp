#include "iostream"

using namespace std;

int reverseNumber(int n,int sum){
    if(n==0){
        return sum;
    }

    sum = sum*10 + n%10;
    return reverseNumber(n/10,sum);
}

bool checkPalindrome(int n){
    if(n == reverseNumber(n,0)){
        return true;
    }
    return false;
}

int main(){
    cout<<checkPalindrome(7852587);
}