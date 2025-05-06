#include "iostream"
#include "vector"

using namespace std;

int sumOfEvenNumber(vector<int> arr,int start,int end){
    if(start == end){
        if(arr[start] % 2 == 0){
            return arr[start];
        }
        else{
            return 0;
        }
    }
    int mid = (start + end) /2;
    int leftSum = sumOfEvenNumber(arr,start,mid);
    int rightSum = sumOfEvenNumber(arr,mid+1,end);
    return leftSum + rightSum;
}

int main(){
    vector<int> arr={45,8,6,9,38,99,2,6};
    cout<<sumOfEvenNumber(arr,0,arr.size()-1)<<endl;
}