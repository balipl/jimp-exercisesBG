//
// Created by Grove on 2017-05-18.
//

#include "FactoryMethod.h"

using namespace factoryMethod;

int main() {

    std::complex<float> cpx1(3, 4);
    std::complex<float> cpx2(3, 4);

    cout << Sum(4, 5) << " " << Sum<int>(4., 5) << " " << Sum(4., 5.) << " " << Sum(cpx1, cpx2)<<endl;


    int *ptr1 = new int(5);
    auto ptr2 = std::make_shared<int>(6);

    auto itr = std::vector<int>(3,5).begin();

    cout  << Value(itr)<<endl;


    std::vector<int> vecint = {3,4,5};
    std::vector<double> vecdoubl = {3.5,4.3,5.6};
    std::vector<std::complex> veccomp = {cpx1,cpx2};
    cout << Mean(vecint) << " " << Mean(vecdoubl) << " " << Mean(veccomp) << " " << endl;




delete(ptr1);
    return 0;
}