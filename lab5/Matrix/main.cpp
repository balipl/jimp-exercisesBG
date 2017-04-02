//
// Created by ASUSTek on 2017-04-02.
//

#include "Matrix.h"

using std::cout;
using std::endl;

int main(){
    cout << "XX" ;
    Matrix m("[1 2 3;3 4 5; 2 3 4]");
    Matrix m2("[3 2 1; 5 4 3; 7 6 5]");

    cout << m.GetSzer() << m.GetWys() << endl;
    cout << m2.GetSzer() << m2.GetWys() << endl;

    cout << m.GetMac(0,0) << endl;
    cout << m.GetMac(1,0)<< endl;
    cout << m.GetMac(2,0)<< endl;
    cout << m.GetMac(0,1)<< endl;
    cout << m.GetMac(1,1)<< endl;
    cout << m.GetMac(2,1)<< endl;
    cout << m.GetMac(0,2)<< endl;



}