#include "iostream"
#include "vector"

using namespace std;

string fun(string song){
    if(song.size() <= 2){
        return song;
    }
    bool flag = false;
    string output = "";
    for (int i = 0; i < song.size(); ++i) {
        if(i<song.size()-2 && song[i] == 'W' && song[i+1]=='U' && song[i+2]=='B'){
            i+=2;
            if(flag){
                output += " ";
            }
            continue;
        }
        output += song[i];
        flag = true;
    }
    return output;
}

int main(){
    string str;
    cin>>str;
    cout<<fun(str);
}
