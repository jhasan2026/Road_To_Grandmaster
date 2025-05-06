#include "iostream"
#include "fstream"

using namespace std;

int main(){
    fstream myFile;
    myFile.open("1_Basic_programming/11_File_Handling/1_write_into_file/write.txt",ios::out);
    if(myFile.is_open()){
        myFile << "Hello"<<endl;
        myFile << "I am Jehan Hasan"<<endl;
        myFile << "I am a student of CSE"<<endl;
        myFile << "My ID is 011221186"<<endl;
        myFile << "My city is Dhaka";
        myFile.close();
    }
}