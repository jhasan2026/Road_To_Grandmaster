#include "iostream"
#include "vector"

using namespace std;

long long sum(long long a, long long n, long long d) {
    return (n * (2 * a + (n - 1) * d)) / 2;
}


long long solve(long long n){
    long long ev=0,od=0;
    if(n%2==0){
        ev = n/2;
        od = n/2;
    }
    else{
        ev = n/2;
        od = (n/2)+1;
    }

    return sum(2,ev,2) - sum(1,od,2);
}

int main(){
    long long n;
    cin>>n;
    cout<<solve(n);
}

