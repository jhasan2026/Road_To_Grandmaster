#include "iostream"
#include "vector"

using namespace std;

double power(int x,int y){
    if(y==1){
        return x;
    }
    double leftPower = 0;
    double rightPower = 0;
    if(y>=0){
        if(y%2==0){
            leftPower = power(x,y/2);
            rightPower = power(x,y/2);
        }
        else{
            leftPower = power(x,y/2);
            rightPower = power(x,y/2+1);
        }
    }
    else{
        if(y%2==0){
            leftPower = 1 / power(x,-1*y/2);
            rightPower = 1 / power(x,-1*y/2);
        }
        else{

            leftPower = 1 / power(x,-1*y/2);
            rightPower = (1 / power(x,-1*y/2))*(1/x);
        }
    }
    return leftPower * rightPower;
}

int main(){
    cout<<power(8,-2)<<endl;
}