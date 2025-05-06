#include "iostream"

using namespace std;

double power(double x,int y){
    if(y==0){
        return 1;
    }
    if(y<0){
        return (1/x)* power(x,y+1);
    }
    else{
        return x * power(x,y-1);
    }

}

int main(){
    cout<<power(5,-3);
}