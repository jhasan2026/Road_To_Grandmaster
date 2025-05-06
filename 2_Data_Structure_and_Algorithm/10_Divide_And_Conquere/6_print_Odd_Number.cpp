#include "iostream"
#include "vector"

using namespace std;

void printOddNumber(vector<int> arr,int start,int end){
    if(start == end){
        if(arr[start] % 2 != 0){
            cout<<arr[start]<<" ";
            return ;
        }
        else{
            return ;
        }
    }
    int mid = (start + end) /2;
    printOddNumber(arr,start,mid);
    printOddNumber(arr,mid+1,end);
}

int main(){
    vector<int> arr={45,8,6,9,38,99,2,6};
    printOddNumber(arr,0,arr.size()-1);
}