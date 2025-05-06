#include "iostream"

using namespace std;

void printASCII(string str){
    for (int i = 0; i < str.length(); ++i) {
        cout<<(int)str[i]<<endl;
    }
}

int main(){
    printASCII("Jehan");
}