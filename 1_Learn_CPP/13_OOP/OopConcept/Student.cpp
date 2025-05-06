#include "iostream"
#include "cstring"
using namespace std;

class Student{
    double cgpa;

public:
    char *name = new char(100);
    int id;

    static int numberOfStudent;                        //static member is accessible by Class (not object)

    static int getNumberOfStudent(){                  //static function can access static data member
        return numberOfStudent;
    }

    //own created :: default constructor
    Student(){
        this->name=NULL;
        this->id=0;
        this->cgpa=0;
        cout<<"Im a student"<<endl;
        numberOfStudent++;
    }

    //parameterized constructor
    Student(char name[]){

        strcpy(this->name,name);
        numberOfStudent++;
    }
    Student(char name[],int id){
        strcpy(this->name,name);
        this->id=id;
        numberOfStudent++;
    }

    Student(char name[],int id,double cgpa){
        strcpy(this->name,name);
        this->id=id;
        this->cgpa=cgpa;
        cout<<endl<<"Parameterized constructor"<<endl;
        numberOfStudent++;
    }

    //copy constructor
    Student(Student &stu){                    //shallow copy :: use safe data memory :: it changes both of them data value
        this->name=stu.name;
        this->id=stu.id;
        this->cgpa=stu.cgpa;
    }

    //getter setter for private member
    double getCgpa(){
        return this->cgpa;
    }
    void setCgpa(double cgpa){
        this->cgpa=cgpa;
    }
    void printInfo(){
        cout<<endl<<"Name: "<< this->name<<" ID:"<< this->id<<" CGPA:"<< this->cgpa<<endl;
    }

};

int Student::numberOfStudent=0;         //initialize static member


//School Class
class SchoolStu : public Student{
    int inClass;
public:
    SchoolStu(char name[],int id,int inClass)
            : Student(name,id)
    {
        this->inClass=inClass;
        numberOfStudent++;
    }                      //use like :: super :: inherited class constructor call
    void printInfo(){
        cout<<endl<<"Name: "<< this->name<<" ID:"<< this->id<<" Class: "<<this->inClass<<endl;
    }
};


//College Class
class CollegeStu : public Student{
    int year;
    char subject;
public:
    CollegeStu(){

    }
    CollegeStu(char name[],int id,double cgpa,int year,char subject)
            : Student(name,id,cgpa)                                    //use like :: super :: inherited class constructor call
    {
        this->year=year;
        this->subject=subject;
        numberOfStudent++;
    }

    void bunk(){
        cout<<"College bunk is impressive"<<endl;
    }


    void printInfo(){
        string sub;
        if(this->subject=='s'){
            sub="Science";
        }
        else if(this->subject=='c'){
            sub="Business study";
        }
        else{
            sub="Arts";
        }
        cout<<endl<<"Name: "<< this->name<<" ID:"<< this->id<<" CGPA:"<< this->getCgpa()<<" Year: "<<this->year<<" Subject:"<<sub <<endl;
    }
};


//University class
class UniversityStu : public Student{
    int course;
    int credit;
public:
    UniversityStu(){

    }
    UniversityStu(char name[],int id,double cgpa,int course,int credit)
    :Student(name,id,cgpa)                                              //use like :: super :: inherited class constructor call
    {
        this->course=course;
        this->credit=credit;
        numberOfStudent++;
    }
    UniversityStu(UniversityStu &uniStu){
        char *temp= new char(strlen(uniStu.name) +1);            //Deep copy for name and id
        int id;


        strcpy(temp,uniStu.name);
        id=uniStu.id;
        this->id=id;


        this->setCgpa(uniStu.getCgpa());                          //shallow copy for other data member
        this->credit=uniStu.credit;
        this->course=uniStu.course;
    }

    void bunk(){
        cout<<"University bunk is very easy"<<endl;
    }


    void printInfo(){
        cout<<endl<<"Name: "<< this->name<<" ID:"<< this->id<<" CGPA:"<< this->getCgpa()<<" Course: "<<this->course<<" Credit:"<< this->credit<<endl;
    }
};


class Adult: public CollegeStu,public UniversityStu{
public:
    Adult(){

    }

};


int main(){
//    Student me;
//    me.name="Myself";
//    me.printInfo();
//
//    Student jehan("Jehan");
//    //jehan.setName("Jehan");
//    jehan.printInfo();
//
//    Student *hasan=new Student("Hasan",221186,3.9);
//    hasan->printInfo();
//
//
//    Student *copyHasan(hasan);
//    copyHasan->printInfo();
//
//    copyHasan->setCgpa(4);
//    copyHasan->printInfo();
//    hasan->printInfo();





//    UniversityStu *uobj=new UniversityStu("Adib Hasan",221698,3.4,13,52);
//    uobj->printInfo();
//
//    UniversityStu *copyUobj(uobj);
//
//    copyUobj->setCgpa(2);
//    copyUobj->id=420;
//
//    copyUobj->printInfo();
//    uobj->printInfo();



//
//    CollegeStu *cobj=new CollegeStu("Mahedi hasan",25698,4.9,2,'c');
//    cobj->printInfo();
//
//    SchoolStu *sobj=new SchoolStu("Imad hasan",789,8);
//    sobj->printInfo();
//
//    cout<<"Number of student:"<<Student::numberOfStudent<<endl;
//
    Adult adt;
    adt.CollegeStu::bunk();
//    adt.UniversityStu::bunk();


}