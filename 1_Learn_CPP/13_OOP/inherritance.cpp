#include "iostream"

using namespace std;
       //single inheritance
class A{
public:
    void funA(){
        cout<<"funA"<<endl;
    }
};
class B : public A{
};


         //multiple inheritance
class C{
public:
    void funC(){
        cout<<"funC"<<endl;
    }
};
class D{
public:
    void funD(){
        cout<<"funD"<<endl;
    }
};
class E : public C ,public D{
public:
};

      //multilevel inheritance
 class F{
public:
void funF(){
        cout<<"funF"<<endl;
    }
};
class G : public F{
public:
    void funG(){
        cout<<"funG"<<endl;
    }
};
class H : public G{
public:
};

int main(){
    //single inheritance
    B b;
    b.funA();
    //multiple inheritance
    E e;
    e.funC();
    e.funD();
    //multilevel inheritance
    H h;
    h.funG();
    h.funF();
}