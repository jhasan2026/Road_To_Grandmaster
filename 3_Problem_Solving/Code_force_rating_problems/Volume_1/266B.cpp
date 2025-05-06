#include "iostream"
#include "vector"

using namespace std;

string solve(int n,int t,string line){
    for (int i = 0; i < t; ++i) {

        for (int j = 0; j < n-1; ++j) {

            if(line[j]=='B' && line[j+1]=='G'){
                line[j] = 'G';
                line[j+1] = 'B';
                j++;
            }

        }

    }
    return line;
}

int main(){
    int n,t;
    cin>>n>>t;
    string str;
    cin>>str;
    cout<<solve(n,t,str);
}