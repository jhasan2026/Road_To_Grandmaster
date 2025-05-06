#include "iostream"
#include "fstream"

using namespace std;

int main(){
    fstream myFile;

    myFile.open("1_Basic_programming/11_File_Handling/4_Append_into_file/numbers.txt",ios::app);
    if(myFile.is_open()){
        myFile <<endl <<"9999" <<endl;
        myFile.close();
    }

}
