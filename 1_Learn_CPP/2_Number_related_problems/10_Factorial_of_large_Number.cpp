#include "iostream"
#include "vector"
using namespace std;

void multiply(vector<int> &result,int num){
    int carry = 0;
    for (int i = 0; i < result.size(); ++i) {
        int product = (result[i] * num) + carry;
        result[i] = product % 10;
        carry = product / 10;
    }
    while (carry){
        result.push_back(carry % 10);
        carry /= 10;
    }
}

void factorialLargeNumber(int n){
    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= n; ++i) {
        multiply(result,i);
    }

    for (int i = result.size()-1; i >= 0 ; --i) {
        cout<<result[i];
    }
}

int main(){
    factorialLargeNumber(20);
}