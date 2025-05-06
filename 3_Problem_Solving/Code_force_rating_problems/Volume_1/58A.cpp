#include "iostream"
#include "vector"

using namespace std;

string solve(string line){
    int state = 1;
    for (int i = 0; i < line.size(); ++i) {
        if(state == 1 && line[i]=='h'){
            state++;
        }
        else if(state == 2 && line[i]=='e'){
            state++;
        }
        else if(state == 3 && line[i]=='l'){
            state++;
        }
        else if(state == 4 && line[i]=='l'){
            state++;
        }
        else if(state == 5 && line[i]=='o'){
            state++;
        }
        if(state == 6){
            return "YES";
        }
    }

    return "NO";
}

int main(){
    string str;
    cin>>str;
    cout<<solve(str);
}