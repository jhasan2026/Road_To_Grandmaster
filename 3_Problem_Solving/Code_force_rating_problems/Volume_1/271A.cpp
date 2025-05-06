#include "iostream"
#include "vector"

using namespace std;

bool checkDist(int n){
    int dig4 = n%10;
    int dig3 = (n%100)/10;
    int dig2 = (n%1000)/100;
    int dig1 = n/1000;
    if(dig1==dig2 || dig1==dig3 || dig1==dig4 || dig2==dig3 || dig2==dig4 || dig3==dig4){
        return false;
    }
    return true;
}

int solve(int y){
    for (int i = 1; i < INT_MAX; ++i) {
        if(checkDist(y+i)){
            return y+i;
        }
    }
    return -1;
}

int main(){
    int y;
    cin>>y;
    cout<<solve(y);
}