#include "iostream"
#include "fstream"
using namespace std;

int main(){
    fstream myfile1;
    myfile1.open("1_Basic_programming/11_File_Handling/5_Marge_two_file/file1.txt",ios::in);

    fstream myfile2;
    myfile2.open("1_Basic_programming/11_File_Handling/5_Marge_two_file/file2.txt",ios::in);

    fstream writeFile;
    writeFile.open("1_Basic_programming/11_File_Handling/5_Marge_two_file/marge.txt",ios::out);

    string line;
    if(myfile1.is_open()){
        while (getline(myfile1,line)){
            writeFile << line<<endl;
        }
        myfile1.close();
    }
    if(myfile2.is_open()){
        while (getline(myfile2,line)){
            writeFile << line<<endl;
        }
        myfile2.close();
    }

}