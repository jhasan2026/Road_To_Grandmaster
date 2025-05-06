#include "iostream"

using namespace std;

class Complex{
    int real;
    int img;
public:
    Complex(int r=0,int i=0){
        real=r;
        img=i;
    }

    Complex operator + (Complex const &obj){
        Complex result;
        result.real =real +obj.real;
        result.img= img +obj.img;
        return result;
    }
    Complex operator - (Complex const &obj){
        Complex result;
        result.real =real -obj.real;
        result.img= img -obj.img;
        return result;
    }
    void display(){

        cout<<real<<" "<<"i*"<<img<<endl;
    }
};

class A{
public:
    void printA1(){
        cout<<"PrintA1"<<endl;
    }

    virtual void printA2(){   //etake ovverride j korbe
                                //compile time e tar
                                //ref change hoye jabe
        cout<<"PrintA2"<<endl;
    }
};
class B : public A{
public:
    virtual void printA1(){
        cout<<"PrintB1"<<endl;
    }

     void printA2(){
        cout<<"PrintB2"<<endl;
    }
};
class C :public B{
public:
    void printA1(){
        cout<<"PrintC1"<<endl;
    }

    void printA2(){
        cout<<"PrintC2"<<endl;
    }
};
int main(){
    Complex c1(12,7);
    Complex c2(6,7);
    Complex c3= c1 + c2;
    Complex c4=c1 - c2;
    c3.display();
    c4.display();

    A *aptr;
    B bObj;
    aptr=&bObj;
    aptr->printA1();
    aptr->printA2();

    B *bptr;
    C cObj;
    bptr=&cObj;
    bptr->printA1();
    bptr->printA2();
}