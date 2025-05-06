#include "iostream"

using namespace std;

long hoursToSec(double hour){
    return hour * 3600;
}

int main(){
    cout<<hoursToSec(1.5);
}