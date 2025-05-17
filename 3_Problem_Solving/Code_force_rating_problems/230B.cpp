#include "iostream"
using namespace std;

string solve(int n){
    int flag = 0;
    for (int i = 2; i < n; ++i) {
        if(n%i == 0 && flag==1){
            return "NO";
        }
        if(n%i == 0){
            flag = 1;
        }
    }
    if(flag == 1) {
        return "YES";
    }
    return "NO";
}

int main(){
    int n,num;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>num;
        cout<<solve(num)<<endl;
    }

}