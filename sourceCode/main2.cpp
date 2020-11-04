//
// Created by Administrator on 2020/4/8.
//
#include <iostream>
#include <string>
using namespace std;
class Base{
private:
    int num=10;
public:
    ~Base(){
      cout<<"Base destroy"<<endl;
    }
};
class Derived:public Base{
private:
    int num =10;
public:
    ~Derived(){
      cout<<"Derived destroy"<<endl;
    }
};
int main(){
  Base *p1,*p2;
  Base *p3;
  p3= new Derived;
  p1= new Base();
  p2= new Derived();
  delete p1;
  delete p2;
  delete p3;
  return 0;
}
