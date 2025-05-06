#include "iostream"
#include "vector"

using namespace std;

void sumOfArray(int *arr,int n,int &sum,long long &product){
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        product *= arr[i];
    }
}

int main(){
    int sum=0;
    long long product=1;
    int arr[5] = {4,5,9,8,2};
    sumOfArray(arr,5,sum,product);
    cout<<sum<<" "<<product;

}