#include "iostream"

using namespace std;

int findLCM(int x,int y){
    static int multipleOfSmall = 0;

    multipleOfSmall += min(x,y);

    if(multipleOfSmall%x==0 and multipleOfSmall%y==0){
        return multipleOfSmall;
    }

    return findLCM(x,y);
}

int main(){
    cout<<findLCM(8,12);
}