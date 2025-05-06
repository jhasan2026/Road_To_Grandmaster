#include "iostream"
#include "vector"

using namespace std;

int countFrequency(vector<int> arr,int key){
    int cnt = 0;
    for (auto x:arr) {
        if(key == x){
            cnt++;
        }
    }
    return cnt;
}

int findMajorityElement(vector<int> arr,int start,int end){
    if(start == end){
        return arr[start];
    }

    int mid = (start+end)/2;
    int leftMajority = findMajorityElement(arr,start,mid);
    int rightMajority = findMajorityElement(arr,mid+1,end);

    if(leftMajority == rightMajority){          //if both are same
        return leftMajority;                        //return any of them
    }

    int leftMajorityFrequency = countFrequency(arr,leftMajority);
    int rightMajorityFrequency = countFrequency(arr,rightMajority);

    if(leftMajorityFrequency >= (end-start+1)/2){
        return leftMajority;
    }
    if(rightMajorityFrequency > (end-start+1)/2){
        return rightMajority;
    }
    return -1;
}

int main(){
    vector<int> arr={-2,-3,4,-3,-2,1,5,-3};
    cout<<findMajorityElement(arr,0,arr.size()-1);
}