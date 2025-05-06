#include "iostream"
#include "fstream"

using namespace std;

int main(){
    fstream mainFile;
    mainFile.open("1_Basic_programming/11_File_Handling/3_even_odd_split/numbers.txt",ios::in);

    fstream oddFile;
    oddFile.open("1_Basic_programming/11_File_Handling/3_even_odd_split/odd.txt",ios::out);



    fstream evenFile;
    evenFile.open("1_Basic_programming/11_File_Handling/3_even_odd_split/even.txt",ios::out);
    

    string line;
    if(mainFile.is_open()){
        while (getline(mainFile,line)){
            int num = stoi(line);
            if(num%2==0){
                evenFile << num <<endl;
            }
            else{
                oddFile <<num <<endl;
            }
        }
        mainFile.close();
    }
}
