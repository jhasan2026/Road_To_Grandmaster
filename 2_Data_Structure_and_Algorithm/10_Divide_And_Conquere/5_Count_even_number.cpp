#include "iostream"
#include "vector"

using namespace std;

int countEvenNumber(vector<int> arr,int start,int end){
    if(start == end){
        if(arr[start] % 2 == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int mid = (start + end) /2;
    int leftCount = countEvenNumber(arr,start,mid);
    int rightCount = countEvenNumber(arr,mid+1,end);
    return leftCount + rightCount;
}

int main(){
    vector<int> arr={45,8,6,9,38,99,2,6};
    cout<<countEvenNumber(arr,0,arr.size()-1)<<endl;
}