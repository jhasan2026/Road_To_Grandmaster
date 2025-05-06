#include "iostream"
#include "fstream"

using namespace std;

int main(){
    fstream myFile;
    myFile.open("1_Basic_programming/11_File_Handling/2_read_from_file/readFromHere.txt",ios::in);
    if(myFile.is_open()){
        string line;
        while (getline(myFile,line)){
            cout<<line<<endl;
        }
        myFile.close();
    }
}