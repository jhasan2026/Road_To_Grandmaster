#include "iostream"

using namespace std;
class Student{
    string name;
public:

    int age;
    bool gender;

    Student(){
        cout<<"Default constructor"<<endl;
    }
    ~Student(){
        cout<<"Destructor"<<endl;
    }
    Student(string str,int ag,int gen){
        cout<<"Parameterized constructor"<<endl;
        name=str;
        age=ag;
        gender=gen;
    }
    Student(string str,int ag){
        cout<<"Parameterized constructor"<<endl;
        name=str;
        age=ag;
        gender=1;
    }
    Student(Student &a){
        cout<<"Copy constructor"<<endl;
        name=a.name;
        age=a.age;
        gender=a.gender;
    }

    //getter setter
    void setName(string str){
        name=str;
    }
    string getName(){
        return name;
    }

    //method
    void printInfo(){
        cout<<"Name: ";
        cout<<name;
        cout<<" Age: ";
        cout<<age;
        cout<<" Gender: ";
        cout<<gender<<endl;
    }

    //operator overloading
    bool operator == (Student &a){
        if(name==a.name && age==a.age && gender==a.gender){
            return true;
        }
        return false;
    }
};
int main(){
//    Student arr[3];
//    for (int i = 0; i < 3; ++i) {
//
//        string s;
//        cin>>s;
//        cout<<"Name: ";
//        arr[i].setName(s);
//
//        cout<<"Age: ";
//        cin>>arr[i].age;
//        cout<<"Gender: ";
//        cin>>arr[i].gender;
//    }
//    for (int i = 0; i < 3; ++i) {
//        arr[i].printInfo();
//    }
    Student a("Jehan",20,1);
    cout<<a.getName()<<endl;
    a.printInfo();
    Student b("Adib",23);
    b.printInfo();
    Student c=a;

    if(c==a){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }

}